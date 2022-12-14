#include "utils.hpp"

#include <stack>

std::vector<std::string> SplitString(const std::string& data) {
  std::vector<std::string> answer;
  std::string tmp = "";
  bool is_bracket = 0;

  for (auto elem : data) {
    if (is_bracket) {
      if (elem == ')') {
        is_bracket = 0;
        if (tmp != "") {
          answer.push_back(tmp);
          tmp = "";
        }
      } else {
        tmp += elem;
      }

      continue;
    }

    if (elem == '(') {
      is_bracket == 1;
      continue;
    }

    if (elem != ' ' && elem != '\t') {
      tmp += elem;
      continue;
    }

    if (tmp != "") {
      answer.push_back(tmp);
      tmp = "";
    }
  }

  if (tmp != "") {
    answer.push_back(tmp);
  }

  return answer;
}
