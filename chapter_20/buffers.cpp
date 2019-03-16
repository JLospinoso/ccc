#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <boost/asio.hpp>

TEST_CASE("const_buffer default constructor") {
  boost::asio::const_buffer cb;
  REQUIRE(cb.size() == 0);
}

TEST_CASE("mutable_buffer default constructor") {
  boost::asio::mutable_buffer mb;
  REQUIRE(mb.size() == 0);
}

TEST_CASE("const_buffer constructor") {
  boost::asio::const_buffer cb{ "Blessed are the cheesemakers.", 7 };

  REQUIRE(cb.size() == 7);
  REQUIRE(*reinterpret_cast<const char*>(cb.data()) == 'B');
}

TEST_CASE("mutable_buffer constructor") {
  std::string proposition{ "Charity for an ex-leper?" };
  boost::asio::mutable_buffer mb{ proposition.data(), proposition.size() };

  REQUIRE(mb.data() == proposition.data());
  REQUIRE(mb.size() == proposition.size());
}

TEST_CASE("streambuf constructor") {
  boost::asio::streambuf sb;

  REQUIRE(sb.size() == 0);
}

TEST_CASE("streambuf input/output") {
  boost::asio::streambuf sb;
  std::ostream os{ &sb };
  os << "Welease Wodger!";

  std::istream is{ &sb };
  std::string command;
  is >> command;

  REQUIRE(command == "Welease");
}
