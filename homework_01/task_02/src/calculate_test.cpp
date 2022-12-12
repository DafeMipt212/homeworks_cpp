#include <gtest/gtest.h>

#include "utils.hpp"

TEST(CalculateTest, simple_sum) {
  ASSERT_EQ(Calculate("1+2"), 3);
  ASSERT_EQ(Calculate("2+2"), 4);
  ASSERT_EQ(Calculate("1+0"), 1);
  ASSERT_EQ(Calculate("0+0"), 0);
}

TEST(CalculateTest, simple_difference) {
  ASSERT_EQ(Calculate("5-2"), 3);
  ASSERT_EQ(Calculate("2-2"), 0);
  ASSERT_EQ(Calculate("1-0"), 1);
  ASSERT_EQ(Calculate("0-0"), 0);
}

TEST(CalculateTest, simple_multiply) {
  ASSERT_EQ(Calculate("5*2"), 10);
  ASSERT_EQ(Calculate("2*2"), 4);
  ASSERT_EQ(Calculate("1*0"), 0);
  ASSERT_EQ(Calculate("0*0"), 0);
}
