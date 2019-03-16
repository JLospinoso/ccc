#include <iostream>
#include <boost/asio.hpp>

int main() {
  boost::asio::io_context io_context;
  boost::asio::ip::tcp::resolver resolver{ io_context };
  boost::asio::ip::tcp::socket socket{ io_context };
  boost::asio::connect(socket, resolver.resolve("www.nostarch.com", "http"));
  // TODO


}
