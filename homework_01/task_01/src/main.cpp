#include <iostream>

#include "utils.hpp"

int main() {
  for (const auto& word : SplitString("a (a a) b (asd as)  ")) {
    std::cout << word << "\n";
  } 
  return 0;
}
