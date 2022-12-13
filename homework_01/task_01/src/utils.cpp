#include "utils.hpp"
#include "iostream"
#include <stack>

std::vector<std::string> SplitString(const std::string& data) {
  std::vector<std::string> out;
  size_t start;
    size_t end = 0;
    int flag = 0;
    int begin = 0;
 
    while ((start = data.find_first_not_of(' ', end)) != std::string::npos)
    {
      if (data[end]==')'){
        flag = 0;
        end += 1;
        out.push_back(data.substr(begin, end - begin));
        continue;
      }
      if (flag == 1){
        end += 1;
        continue;
      }
      if (data[start]=='('){
        begin = start;
        flag = 1;
        continue;
      }
      if (data[start]=='\t'){
        start += 1;
      }
      end = data.find(' ', start);
      if (data.find('\t', start) < data.find(' ', start)){
        end = data.find('\t', start);
      }
      out.push_back(data.substr(start, end - start));
    }
    return out;
}
