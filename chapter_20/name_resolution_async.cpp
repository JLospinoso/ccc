#include <boost/asio.hpp>
#include <iostream>

int main() {
  boost::asio::io_context io_context;
  boost::asio::ip::tcp::resolver resolver{ io_context };
  resolver.async_resolve("www.nostarch.com", "http", [](boost::system::error_code ec, const auto& results) {
    if(ec) {
      std::cerr << "Error:" << ec << std::endl;
      return;
    }
    for(auto&& result : results) {
      std::cout << result.service_name() << " " << result.host_name() << " " << result.endpoint() << " " << std::endl;
    }
  });
  io_context.run();
}
