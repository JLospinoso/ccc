#define CATCH_CONFIG_MAIN
#include <array>
#include <catch2/catch.hpp>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

TEST_CASE("plus") {
  plus<short> adder;
  REQUIRE(3 == adder(1, 2));
  REQUIRE(3 == plus<short>{}(1, 2));
}

TEST_CASE("iota") {
  array<int, 3> easy_as;
  iota(easy_as.begin(), easy_as.end(), 1);
  REQUIRE(easy_as == array<int, 3>{ 1, 2, 3 });
}

TEST_CASE("accumulate") {
  vector<int> nums{ 1, 2, 3 };
  const auto result1 = accumulate(nums.begin(), nums.end(), -1);
  REQUIRE(result1 == 5);

  const auto result2 = accumulate(nums.begin(), nums.end(), 2, multiplies<>());
  REQUIRE(result2 == 12);
}

TEST_CASE("reduce") {
  vector<int> nums{ 1, 2, 3 };
  const auto result1 = std::reduce(nums.begin(), nums.end(), -1);
  REQUIRE(result1 == 5);

  const auto result2 = reduce(nums.begin(), nums.end(), 2, multiplies<>());
  REQUIRE(result2 == 12);
}

TEST_CASE("inner_product") {
  vector<int> nums1{ 1, 2, 3, 4, 5 };
  vector<int> nums2{ 1, 0, -1, 0, 1 };
  const auto result = inner_product(nums1.begin(), nums1.end(), nums2.begin(), 10);
  REQUIRE(result == 13);
}

TEST_CASE("adjacent_difference") {
  vector<int> fib{ 1, 1, 2, 3, 5, 8 }, fib_diff;
  adjacent_difference(fib.begin(), fib.end(), back_inserter(fib_diff));
  REQUIRE(fib_diff == vector<int>{ 1, 0, 1, 1, 2, 3 });
}

TEST_CASE("partial_sum") {
  vector<int> num{ 1, 2, 3, 4 }, result;
  partial_sum(num.begin(), num.end(), back_inserter(result));
  REQUIRE(result == vector<int>{ 1, 3, 6, 10 });
}
