#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <random>

TEST_CASE("mt19937_64 is pseudorandom") {
  std::mt19937_64 mt_engine{ 91586 };
  REQUIRE(mt_engine() == 8346843996631475880);
  REQUIRE(mt_engine() == 2237671392849523263);
  REQUIRE(mt_engine() == 7333164488732543658);
}

TEST_CASE("std::random_device is invocable") {
  std::random_device rd_engine{};
  REQUIRE_NOTHROW(rd_engine());
}

TEST_CASE("std::uniform_int_distribution produces uniform ints") {
  std::mt19937_64 mt_engine{ 102787 };
  std::uniform_int_distribution<int> int_d{ 0, 10 };
  const size_t n{ 1'000'000 };
  int sum{};
  for(size_t i{}; i < n; i++)
    sum += int_d(mt_engine);
  const auto sample_mean = sum / double{ n };
  REQUIRE(sample_mean == Approx(5).epsilon(0.1));
}
