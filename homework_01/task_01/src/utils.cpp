#include "utils.hpp"
#include <iostream>
#include <stack>

std::vector<std::string> SplitString(const std::string& data) {
  std::vector<std::string> symbs;
  std::string symb = "";
  int flag = 0;
  for (char const& ch : data) {
    if (flag == 0) {
      if (ch == '(') {
        flag = 1;
      } else if (ch != ' ' and ch != '\t') {
        symb.push_back(ch);
      } else if (ch == ' ' or ch == '\t') {
        if (!symb.empty()) {
          symbs.push_back(symb);
          symb.clear();
        }
      };
    };
    if (flag == 1) {
      if (ch != ')') {
        symb.push_back(ch);
      } else if (ch == ')') {
        symb.push_back(ch);
        if (!symb.empty()) {
          symbs.push_back(symb);
          symb.clear();
        }
        flag = 0;
      };
    };
  };
  if (!symb.empty()) {
    symbs.push_back(symb);
    symb.clear();
  }
  return {symbs};
};