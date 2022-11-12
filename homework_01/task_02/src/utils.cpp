#include "utils.hpp"
#include <iostream>
#include <stack>

int Calculate(const std::string &data) {
  char element_a = data[0];

  int int_a = int(element_a);

  char action = data[1];

  char element_b = data[2];

  int int_b = int(element_b);

  if (action == '+') {
    return element_a + element_b;
  }
  if (action == '-') {
    return element_a - element_b;
  }
  if (action == '/') {
    return element_a / element_b;
  }
  if (action == '*') {
    return element_a * element_b;
  }
}