#include <boost/algorithm/string/case_conv.hpp>
#include <boost/asio.hpp>
#include <future>
#include <iostream>
#include <memory>
#include <string>

using namespace boost::asio;

struct Session : std::enable_shared_from_this<Session> {
  explicit Session(ip::tcp::socket socket)
      : socket{ std::move(socket) } {}
  void read() {
    async_read_until(socket,
                     dynamic_buffer(message),
                     '\n',
                     [self = shared_from_this()](boost::system::error_code ec, std::size_t length) {
                       if(ec || self->message == "\n")
                         return;
                       boost::algorithm::to_upper(self->message);
                       self->write();
                     });
  }
  void write() {
    async_write(socket, buffer(message), [self = shared_from_this()](boost::system::error_code ec, std::size_t length) {
      if(ec)
        return;
      self->message.clear();
      self->read();
    });
  }

  private:
  ip::tcp::socket socket;
  std::string message;
};

void serve(ip::tcp::acceptor& acceptor) {
  acceptor.async_accept([&acceptor](boost::system::error_code ec, ip::tcp::socket socket) {
    serve(acceptor);
    if(ec)
      return;
    auto session = std::make_shared<Session>(std::move(socket));
    session->read();
  });
}

int main() {
  int n_threads{ 4 };
  boost::asio::io_context io_context{ n_threads };
  ip::tcp::acceptor acceptor{ io_context, ip::tcp::endpoint(ip::tcp::v4(), 8123) };
  serve(acceptor);

  std::vector<std::future<void>> futures;
  std::generate_n(std::back_inserter(futures), n_threads, [&io_context] {
    return std::async(std::launch::async, [&io_context] { io_context.run(); });
  });

  for(auto& future : futures) {
    try {
      future.get();
    } catch(std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }
}
