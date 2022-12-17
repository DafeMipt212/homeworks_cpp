#include "utils.hpp"

#include <string>
#include <string_view>
#include <vector>

std::vector<std::string> SplitString(std::string const& data) {
  std::vector<std::string> result;
  std::string token = "";
  bool brackets_condition = false;
  for (char const& active_element : data) {
    if (brackets_condition) {
      token.push_back(active_element);
      if (active_element == ')') {
        brackets_condition = false;
        result.push_back(token);
        token = "";
      }
    } else {
      if (active_element == ' ' || active_element == '\t') {
        if (!token.empty()) {
          result.push_back(token);
          token = "";
        }
      } else {
        active_data.push_back(active_element);
        if (active_element == '(') brackets_condition = true;
      }
    }
  }
  if (!token.empty()) {
    result.push_back(active_data);
    token = "";
  }
  return result;
};
