#include "utils.hpp"

#include <string.h>

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
std::vector<std::string> SplitString(const std::string& data) {
  std::vector<std::string> v;
  std::string buff = "";
  bool flag = false;  //скобки закрыты (или их нет)
  cout << size(data) << endl;
  for (int i = 0; i < size(data); ++i) {
    if (data[i] == '(') {
      flag = true;  //скобки открыты
    } else if (data[i] == ')') {
      flag = false;  //скобки закрыты
    }
    if (((data[i] != ' ') and (data[i] != '\t')) or (flag == true)) {
      buff += data[i];
    }
    cout << "Data" << i << " : " << data[i] << endl;
    cout << "Buff: " << buff << endl;
    if (flag == false) {
      if ((data[i] == ' ') or (data[i] == '\t') or (i + 1 >= size(data))) {
        if (buff != "") {
          v.push_back(buff);
          buff = "";
        }
      }
    } else {
      if (i + 1 >= size(data)) {
        if (buff != "") {
          v.push_back(buff);
          buff = "";
        }
      }
    }
  }
  std::cout << "Size of vector: " << v.size() << "\n";
  return v;
}
