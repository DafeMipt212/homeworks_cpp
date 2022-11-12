#include <string>
#include <string_view>
#include <vector>

std::vector<std::string> SplitString(const std::string &data) {
  std::vector<std::string> words;
  std::string word = "";
  int check_int = 0;
  for (char const &symbol : data) {
    if (check_int == 0) {
      if (symbol == '(') {
        check_int = 1;
      } else if (symbol != ' ' and symbol != '\t') {
        word.push_back(symbol);
      } else if (symbol != ' ' or symbol == '\t') {
        if (!word.empty()) {
          words.push_back(word);
          word.clear();
        }
      };
    };
    if (check_int == 1) {
      if (symbol != ')') {
        word.push_back(symbol);
      } else if (symbol == ')') {
        word.push_back(symbol);
        if (!word.empty()) {
          words.push_back(word);
          word.clear();
        }
        check_int = 0;
      };
    };
  };
  if (!word.empty()) {
    words.push_back(word);
    word.clear();
  }
  return {words};
};