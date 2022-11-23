#include <iostream>
#include <utils.hpp>

int main() {
  std::string line;
  line = "a\na\ta a";
  for (const auto& word : SplitString(line)) {
    std::cout << word << '\n';
  }
  return 0;
}
