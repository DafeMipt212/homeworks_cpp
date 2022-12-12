#include "catch2/catch_test_macros.hpp"
#include <catch2/catch_approx.hpp>


#include "utils.hpp"

TEST_CASE("Calculate", "[simple_sum]") {
  CHECK(Calculate("1+2") == 3);
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
  CHECK(Calculate("5*2") == 10);
  CHECK(Calculate("2*2") == 4);
  CHECK(Calculate("1*0") == 0);
  CHECK(Calculate("0*0") == 0);
}

TEST_CASE("Calculate", "[simple_division]") {
  CHECK(Calculate("10/2") == 5);
  CHECK(Calculate("4/2") == 2);
  CHECK(Calculate("0/1") == 0);
}

TEST_CASE("Calculate", "[advanced_expressions]") {
  CHECK(Calculate("-6/2-10/5") == -5);
  CHECK(Calculate("6+10/2*2/2-1") == 10);
  CHECK(Calculate("5/2-2.6*10") == Catch::Approx(-23.5));
  CHECK(Calculate("(2+3)+5") == 10);
  CHECK(Calculate("(-2)+(-2)*(-2)") == 2);
  CHECK(Calculate("(3/10)+(2.5*2)") == Catch::Approx(5.3));
}
