#include <boost/asio.hpp>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

std::string make_request(std::string host, boost::asio::io_context& io_context) {
  std::stringstream request_stream;
  request_stream << "GET / HTTP/1.1\r\n"
                    "Host: "
                 << host
                 << "\r\n"
                    "Accept: text/html\r\n"
                    "Accept-Language: en-us\r\n"
                    "Accept-Encoding: identity\r\n"
                    "Connection: close\r\n\r\n";
  const auto request = request_stream.str();
  boost::asio::ip::tcp::resolver resolver{ io_context };
  const auto endpoints = resolver.resolve(host, "http");
  boost::asio::ip::tcp::socket socket{ io_context };
  const auto connected_endpoint = boost::asio::connect(socket, endpoints);
  boost::asio::write(socket, boost::asio::buffer(request));
  std::string response;
  boost::system::error_code ec;
  boost::asio::read(socket, boost::asio::dynamic_buffer(response), ec);
  if(ec && ec.value() != 2)
    throw boost::system::system_error{ ec };
  return response;
}

int main() {
  boost::asio::io_context io_context;
  try {
    const auto response = make_request("www.arcyber.army.mil", io_context);
    std::cout << response << "\n";
  } catch(boost::system::system_error& se) {
    std::cerr << "Error: " << se.what() << std::endl;
  }
}
