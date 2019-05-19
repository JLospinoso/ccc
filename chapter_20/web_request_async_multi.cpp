#include <algorithm>
#include <boost/asio.hpp>
#include <future>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using ResolveResult = boost::asio::ip::tcp::resolver::results_type;
using Endpoint = boost::asio::ip::tcp::endpoint;

struct Request {
  explicit Request(boost::asio::io_context& io_context, std::string host)
      : resolver{ io_context }
      , socket{ io_context }
      , host{ std::move(host) } {
    std::stringstream request_stream;
    request_stream << "GET / HTTP/1.1\r\n"
                      "Host: "
                   << this->host
                   << "\r\n"
                      "Accept: text/plain\r\n"
                      "Accept-Language: en-us\r\n"
                      "Accept-Encoding: identity\r\n"
                      "Connection: close\r\n\r\n";
    request = request_stream.str();
    resolver.async_resolve(this->host, "http", [this](boost::system::error_code ec, const ResolveResult& results) {
      resolution_handler(ec, results);
    });
  }

  void resolution_handler(boost::system::error_code ec, const ResolveResult& results) {
    if(ec) {
      std::cerr << "Error resolving " << host << ": " << ec << std::endl;
      return;
    }
    boost::asio::async_connect(socket, results, [this](boost::system::error_code ec, const Endpoint& endpoint) {
      connection_handler(ec, endpoint);
    });
  }

  void connection_handler(boost::system::error_code ec, const Endpoint& endpoint) {
    if(ec) {
      std::cerr << "Error connecting to " << host << ": " << ec.message() << std::endl;
      return;
    }
    boost::asio::async_write(
        socket, boost::asio::buffer(request), [this](boost::system::error_code ec, size_t transferred) {
          write_handler(ec, transferred);
        });
  }

  size_t write_handler(boost::system::error_code ec, size_t transferred) {
    if(ec) {
      std::cerr << "Error writing to " << host << ": " << ec.message() << std::endl;
      return 0;
    }
    const auto remaining = request.size() - transferred;
    if(remaining)
      return remaining;
    boost::asio::async_read(
        socket, boost::asio::dynamic_buffer(response), [this](boost::system::error_code ec, size_t transferred) {
          read_handler(ec, transferred);
        });
    return 0;
  }

  void read_handler(boost::system::error_code ec, size_t transferred) {
    if(ec && ec.value() != 2)
      std::cerr << "Error reading from " << host << ": " << ec.message() << std::endl;
  }

  const std::string& get_response() const noexcept {
    return response;
  }

  private:
  boost::asio::ip::tcp::resolver resolver;
  boost::asio::ip::tcp::socket socket;
  std::string request, response;
  const std::string host;
};

int main() {
  size_t n_requests{ 1 }, n_threads{ 1 };
  boost::asio::io_context io_context{ static_cast<int>(n_threads) };

  std::vector<Request> requests;
  std::generate_n(std::back_inserter(requests), n_requests, [&io_context] {
    return Request{ io_context, "www.arcyber.army.mil" };
  });

  std::vector<std::future<void>> futures;
  std::generate_n(std::back_inserter(futures), n_threads, [&io_context] {
    return std::async(std::launch::async, [&io_context] { io_context.run(); });
  });

  for(auto& future : futures)
    future.get();
  for(const auto& request : requests)
    std::cout << "Response had length " << request.get_response().size();
}
