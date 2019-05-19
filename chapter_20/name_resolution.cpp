#include <boost/asio.hpp>
#include <iostream>

int main() {
  boost::asio::io_context io_context;
  boost::asio::ip::tcp::resolver resolver{ io_context };
  boost::system::error_code ec;
  for(auto&& result : resolver.resolve("www.nostarch.com", "http", ec)) {
    std::cout << result.service_name() << " " << result.host_name() << " " << result.endpoint() << " " << std::endl;
  }
  if(ec)
    std::cout << "Error code: " << ec << std::endl;
}
