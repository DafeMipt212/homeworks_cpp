#include "utils.hpp"

#include <cstring>
#include <iostream>
#include <stack>

int Calculate(const std::string &data) {
  std::string number = "";
  char action;
  int variables[2];
  int answer = 0;

  for (char c : data) {
    if (c >= '0' && c <= '9') {
      number = number + c;
    } else {
      numbers.push_back(std::stoi(number_part)) number.clear();
      if ((c == '+') || (c == '-') || (c == '*') || (c == '/')) {
        action = c;
      }
    }
  }

  int_numbers[n] = atoi(number.c_str());

  if (action == '+') {
    answer = (int_numbers[0] + int_numbers[1]);
  }
  if (action == '-') {
    answer = (int_numbers[0] - int_numbers[1]);
  }
  if (action == '*') {
    answer = (int_numbers[0] * int_numbers[1]);
  }
  if (action == '/') {
    answer = (int_numbers[0] / int_numbers[1]);
  }
  return answer;
}