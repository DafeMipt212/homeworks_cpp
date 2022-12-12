#include <iostream>

#include "utils.hpp"

int main() {
  std::string data;
  std::getline(std::cin, data);
  std::cout << Calculate(data)<<std::endl;
  return 0;
}
