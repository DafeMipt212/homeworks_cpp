#include "utils.hpp"

#include <iostream>
#include <stack>
#include <regex>
#include <vector>

using namespace std;


std::vector<string> SplitString(const std::string& data) {
    vector<string> result;
    std::string word;
    int flag = 0;
    for (auto c : data) {
      if(c == ')'){
        word += c;
        flag = 0;
        continue;
      }
      if(flag == 1){
        word += c;
        continue;
      }
      if(c == '('){
        word += c;
        flag = 1;
        continue;
      }
      if(c != ' ' && c != '\t') {
        word += c;
      }
      else if(!word.empty()) {
        result.push_back(word);
        word = "";
      }
    }
    if(!word.empty()){
      result.push_back(word);
    }
    return result;
}
