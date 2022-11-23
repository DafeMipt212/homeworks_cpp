#include "utils.hpp"

#include <string.h>

#include <iostream>
#include <regex>
#include <stack>
#include <string>
#include <vector>
using namespace std;

std::vector<std::string> SplitString(const std::string& data) {
  std::vector<std::string> v;
  std::string buff = "";
  bool flag = false;
  for (int i = 0; i < size(data); ++i) {
    if (data[i] == '(') {
      flag = true;
    } else if (data[i] == ')') {
      flag = false;
    }
    if (((data[i] != ' ') and (data[i] != '\t') and (data[i] != '+') and
         (data[i] != '-') and (data[i] != '*') and (data[i] != '/')) or
        (flag == true)) {
      buff += data[i];
    }
    if (flag == false) {
      if ((data[i] == ' ') or (data[i] == '\t') or (data[i] == '+') or
          (data[i] == '-') or (data[i] == '*') or (data[i] == '/') or
          (i + 1 >= size(data))) {
        if (buff != "") {
          v.push_back(buff);
          buff = "";
          if ((data[i] == '+') or (data[i] == '-') or (data[i] == '*') or
              (data[i] == '/')) {
            buff += data[i];
            v.push_back(buff);
            buff = "";
          }
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
  return v;
}

int Calculate(const std::string& data) {
  int i = 0;
  int buff_int = 0;
  std::string znak;
  int rez = 0;
  vector<int> chisla;
  vector<string> r = SplitString(data);
  for (i = 0; i < r.size(); ++i) {
    if ((r[i] != "+") and (r[i] != "-") and (r[i] != "*") and (r[i] != "/")) {
      chisla.push_back(stoi(r[i]));
    } else {
      znak = r[i];
    }
  }
  if (!chisla.empty())
    rez = chisla[0];
  else {
    cout << "Error" << endl;
    rez = -1;
  }
  if (!chisla.empty()) {
    for (i = 1; i < chisla.size(); ++i) {
      if (znak == "+") {
        rez += chisla[i];
      }
      if (znak == "-") {
        rez -= chisla[i];
      }
      if (znak == "*") {
        rez *= chisla[i];
      }
      if (znak == "/") {
        rez /= chisla[i];
      }
    }
  }
  return rez;
}
