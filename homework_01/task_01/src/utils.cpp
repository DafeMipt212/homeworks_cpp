#include "utils.hpp"
#include <iostream>
#include <stack>

std::vector<std::string> SplitString(const std::string& data) {
  std::vector<std::string> symbols;
  std::string symbol = "";
  int flag = 0;
  for (char const& ch : data) {
    if (flag == 0) {
      if (ch == '(') {
        flag = 1;
      } else if (ch != ' ' and ch != '\t') {
        symbol += ch;
      } else if (ch == ' ' or ch == '\t') {
        if (!symbol.empty()) {
          symbols.push_back(symbol);
          symbol.clear();
        }
      };
    };
    if (flag == 1) {
      if (ch != ')') {
        symbol += ch;
      } else if (ch == ')') {
        symbol += ch;
        if (!symbol.empty()) {
          symbols.push_back(symbol);
          symbol.clear();
        }
        flag = 0;
      };
    };
  };
  if (!symbol.empty()) {
    symbols.push_back(symbol);
    symbol.clear();
  }
  
  return {symbols};
}