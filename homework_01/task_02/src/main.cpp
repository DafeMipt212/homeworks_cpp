#include <iostream>

#include "utils.hpp"

int main() {
  std::string data;
  std::getline(std::cin, data);

  try {
    std::cout << Calculate(data);
  } catch (std::string error) {
    std::cout << error;
  }

  return 0;
}
