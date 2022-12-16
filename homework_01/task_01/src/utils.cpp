#include "utils.hpp"

#include <iostream>
#include <stack>

std::vector<std::string> SplitString(const std::string& data) {
  std::vector<std::string> out;
  size_t word_start;
  size_t word_end = 0;
  bool in_brackets = false;
  size_t opening_bracket = 0;
 
    while ((word_start = data.find_first_not_of(' ', word_end)) != std::string::npos)
    {
      if (data[word_end]==')'){
        in_brackets = false;
        word_end += 1;
        out.push_back(data.substr(opening_bracket, word_end - opening_bracket));
        continue;
      }
      if (in_brackets == 1){
        word_end += 1;
        continue;
      }
      if (data[word_start]=='('){
        opening_bracket = word_start;
        in_brackets = 1;
        continue;
      }
      if (data[word_start]=='\t'){
        word_start += 1;
      }
      word_end = data.find(' ', word_start);
      if (data.find('\t', word_start) < data.find(' ', word_start)){
        word_end = data.find('\t', word_start);
      }
      out.push_back(data.substr(word_start, word_end - word_start));
    }
    return out;
}
