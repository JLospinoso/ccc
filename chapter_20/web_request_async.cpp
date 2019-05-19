#include <algorithm>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <sstream>
#include <string>

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
                      "Accept: text/html\r\n"
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

  void write_handler(boost::system::error_code ec, size_t transferred) {
    if(ec) {
      std::cerr << "Error writing to " << host << ": " << ec.message() << std::endl;
    } else if(request.size() != transferred) {
      request.erase(0, transferred);
      boost::asio::async_write(
          socket, boost::asio::buffer(request), [this](boost::system::error_code ec, size_t transferred) {
            write_handler(ec, transferred);
          });
    } else {
      boost::asio::async_read(
          socket, boost::asio::dynamic_buffer(response), [this](boost::system::error_code ec, size_t transferred) {
            read_handler(ec, transferred);
          });
    }
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
  boost::asio::io_context io_context;
  Request request{ io_context, "www.arcyber.army.mil" };
  io_context.run();
  std::cout << request.get_response();
}
