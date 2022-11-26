#include "utils.hpp"
#include <string>
#include <string_view>
#include <vector>

std::vector<std::string> SplitString(std::string const& data) {
  std::vector<std::string> end_of_working;
  std::string active_data = "";
  std::string skob_index = "False";


  for (char const& word_symbol : data) {
    if (skob_index == "False") {
      if (word_symbol == '(') {
        skob_index = "True";
      } 
      else if (word_symbol != ' ') {
        if (word_symbol != '\t'){
          active_data.push_back(word_symbol);
        } 
        else if (!active_data.empty()) {
          end_of_working.push_back(active_data);
          active_data.clear();
        }
      };
    };


    if (skob_index == "True") {
      if (word_symbol != ')') {
        active_data.push_back(word_symbol);
      } 
      else if (word_symbol == ')') {
        active_data.push_back(word_symbol);
        if (!active_data.empty()) {
          end_of_working.push_back(active_data);
          active_data.clear();
        }
        skob_index = "False";
      };
    };
  };



  if (!active_data.empty()) {
    end_of_working.push_back(active_data);
    active_data.clear();
  }
  return end_of_working;
};