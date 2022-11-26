#include "utils.hpp"

#include <cstring>
#include <iostream>
#include <stack>

int Calculate(const std::string &data) {
  std::string number = "";
  char action;
  int int_number = 0;
  int int_numbers[2];
  int n = 0;
  int i = 0;
  int answer = 0;

  for (char c : data) {
    if ((c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') ||
        (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9')) {
      number = number + c;
    } else {
      int_number = atoi(number.c_str());
      int_numbers[n] = int_number;
      n = n + 1;
      number.clear();
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