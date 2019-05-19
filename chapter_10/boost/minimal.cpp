#define BOOST_TEST_MODULE TestModuleName
#include <boost/test/included/unit_test.hpp>

struct MyTestFixture {};

BOOST_FIXTURE_TEST_CASE(MyTestA, MyTestFixture) {
  // Test A here
}

BOOST_FIXTURE_TEST_CASE(MyTestB, MyTestFixture) {
  // Test A here
}
