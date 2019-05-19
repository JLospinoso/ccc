#include <boost/asio.hpp>
#include <iostream>

int main() {
  boost::asio::io_context io_context;
  boost::asio::ip::tcp::resolver resolver{ io_context };
  boost::asio::ip::tcp::socket socket{ io_context };
  boost::asio::async_connect(socket,
                             resolver.resolve("www.nostarch.com", "http"),
                             [](boost::system::error_code ec, const auto& endpoint) { std::cout << endpoint; });
  io_context.run();
}
