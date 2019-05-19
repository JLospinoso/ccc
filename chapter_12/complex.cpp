#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <complex>

TEST_CASE("std::complex::complex has a real and imaginary component") {
  std::complex<double> a{ 0.5, 14.13 };
  REQUIRE(std::real(a) == 0.5);
  REQUIRE(std::imag(a) == 14.13);
}

#include <boost/math/constants/constants.hpp>
#include <cmath>

TEST_CASE("boost::math offers constants") {
  using namespace boost::math::double_constants;
  auto sphere_volume = four_thirds_pi * std::pow(10, 3);
  REQUIRE(sphere_volume == Approx(4188.7902047));
}

#include <limits>
TEST_CASE("std::numeric_limits provides the smallest finite value.") {
  auto my_cup = std::numeric_limits<int>::min();
  auto underfloweth = my_cup - 1;
  REQUIRE(underfloweth > my_cup);
}

#include <boost/numeric/conversion/converter.hpp>
using double_to_int = boost::numeric::converter<int, double>;

TEST_CASE("boost::numeric::converter") {
  REQUIRE(double_to_int::convert(3.14159) == 3);

  double_to_int dti;
  REQUIRE(dti(3.501) == 3);

  REQUIRE(double_to_int{}(2.71) == 2);

  auto yuge = std::numeric_limits<double>::max();
  REQUIRE_THROWS_AS(dti(yuge), boost::numeric::positive_overflow);

  auto tiny = -1 * std::numeric_limits<double>::max();
  REQUIRE_THROWS_AS(dti(tiny), boost::numeric::negative_overflow);
}

#include <boost/numeric/conversion/cast.hpp>
#include <limits>

TEST_CASE("boost::boost::numeric_cast checks overflow") {
  auto yuge = std::numeric_limits<double>::max();
  REQUIRE_THROWS_AS(boost::numeric_cast<int>(yuge), boost::numeric::positive_overflow);
}

#include <ratio>

TEST_CASE("std::ratio") {
  using ten = std::ratio<10, 1>;
  using two_thirds = std::ratio<2, 3>;
  using result = std::ratio_multiply<ten, two_thirds>;
  REQUIRE(result::num == 20);
  REQUIRE(result::den == 3);
}
