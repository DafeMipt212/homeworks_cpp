#include "utils.hpp"

#include <stack>

std::vector<std::string> SplitString(const std::string& data) {
  std::vector<std::string> v;
  std::string tmp = "";

  for (auto c : s) {
    if (c != ' ') {
      tmp += c;
      continue;
    }

    if (tmp != "") {
      v.push_back(tmp);
      tmp = "";
    }
  }

  if (tmp != "") {
    v.push_back(tmp);
  }

  return v;
}
