#include "gtest/gtest.h"

struct MyTestFixture : ::testing::Test {};

TEST_F(MyTestFixture, MyTestA) {
  // Test A here
}

TEST_F(MyTestFixture, MyTestB) {
  // Test B here
}
