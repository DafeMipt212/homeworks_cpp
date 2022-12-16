#include <catch2/catch_test_macros.hpp>

#include "utils.hpp"


#include "utils.hpp"

#include <cassert>

int main() {
    assert(1 == Сalculate("1"));
    assert(3 == Сalculate("1 + 2"));
    assert(7 == Сalculate("1 + 2 * 3"));
    assert(-1 == Сalculate("1 + 2 * 3 / 2 - 5"));
    assert(0 == Сalculate("0 + 0"));
    assert(0 == Сalculate("0 - 0"));
    assert(0 == Сalculate("2 - 2"));
    assert(2 == Сalculate("2 / 1"));
    assert(11617 == Сalculate("23234 / 2"));
    assert(71 == Сalculate("8 * 9 * 1 - 6 + 5"));
    assert(569 == Сalculate("1 + 23 * 5 + 453"));
    assert(863074 == Сalculate("863297 - 223"));
    assert(11175 == Сalculate("2235 * 5"));
    assert(336247 == Сalculate("8223 + 328024"));
    assert(4 == Сalculate("8 / 2"));
    assert(550 == Сalculate("69 * 9 - 71"));
    assert(-1 == Сalculate("5 - 3 * 2"));

    return 0;
}

