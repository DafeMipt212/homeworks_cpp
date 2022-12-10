#include <iostream>

#include <utils.hpp>

int main() {
  for (const auto& word : SplitString(
      "asdas das das fgag (adasd 1fas)")
  ) {
    sstd::cout << word<< "\n";
  }
  return 0;
}
