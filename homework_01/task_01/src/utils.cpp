#include "utils.hpp"

#include <stack>

/*std::vector<std::string> SplitString(const std::string& data) {
  return {};
}*/

std::vector<std::string> SplitString(const std::string &str) {
  std::vector<char> braces;
  std::vector<std::string> res;
  std::string temp;
  for (auto c : str) {
    if ((c != ' ') and (c != '\t')) {
      temp += c;
    } else if (braces.size() != 0) {
      temp += c;
    } else if (!temp.empty()) {
      res.push_back(temp);
      temp.clear();
    }
    if (c == '(') {
      braces.push_back(c);
    } else if ((braces.size() > 0) && (c == ')')) {
      if (braces.back() == '(') {
        braces.pop_back();
      }
    }
  }
  if (!temp.empty()) {
    res.push_back(temp);
  }
  return res;
}