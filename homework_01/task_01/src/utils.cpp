#include "utils.hpp"

#include <stack>

std::vector<std::string> SplitString(const std::string& data) {
  std::vector<std::string> answer;
  std::string tmp = "";

  for (auto elem : data) {
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
