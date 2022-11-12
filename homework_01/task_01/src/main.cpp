#include <iostream>

#include <utils.hpp>

int main() {
  std::string line;
  /*std::getline(std::cin, line);
  for (const auto& word : SplitString(line)) {
    std::cout << word << '\n';
  }*/
  line="a\na\ta a";
    for (const auto& word : SplitString(line)) {
    std::cout << word << '\n';
  }
  return 0;
}
