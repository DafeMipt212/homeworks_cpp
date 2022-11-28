#include <string>
#include <string_view>
#include <vector>
std::vector<std::string> SplitString(std::string const& data) {
  std::vector<std::string> finish_array;
  std::string active_data = "";
  bool brackets_condition = false;
  for (char const& active_element : data) {
    if (brackets_condition) {
      active_data.push_back(active_element);
      if (active_element == ')') {
        brackets_condition = false;
        finish_array.push_back(active_data);
        active_data = "";
      };
    } else {
      if (active_element == ' ' || active_element == '\t') {
        if (!active_data.empty()) {
          finish_array.push_back(active_data);
          active_data = "";
        }
      } else {
        active_data.push_back(active_element);
        if (active_element == '(') brackets_condition = true;
      }
    };
  };
  if (!active_data.empty()) {
    finish_array.push_back(active_data);
    active_data = "";
  }
  return finish_array;
};
