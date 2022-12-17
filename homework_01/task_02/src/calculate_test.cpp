#include <catch2/catch_test_macros.hpp>

#include "utils.hpp"

TEST_CASE("Calculate", "[simple_sum]") {
  CHECK(Calculate("12+2") == 14);
  CHECK(Calculate("2+2") == 4);
  CHECK(Calculate("1+0") == 1);
  CHECK(Calculate("0+0") == 0);
}

TEST_CASE("Calculate", "[simple_difference]") {
  CHECK(Calculate("5-2") == 3);
  CHECK(Calculate("2-2") == 0);
  CHECK(Calculate("1-0") == 1);
  CHECK(Calculate("0-0") == 0);
}

TEST_CASE("Calculate", "[simple_multiply]") {
  CHECK(Calculate("52*2") == 104);
  CHECK(Calculate("2*2") == 4);
  CHECK(Calculate("1*0") == 0);
  CHECK(Calculate("0*0") == 0);
}

TEST_CASE("Calculate", "[simple_del]") {
  CHECK(Calculate("52/2") == 26);
  CHECK(Calculate("2/2") == 1);
  CHECK(Calculate("0/3") == 0);
  CHECK(Calculate("23/1") == 23);
}