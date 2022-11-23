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

bool IsInt_bad_version(const std::string& str) {
  int a = 1;
  bool flag = true;
  if (str.empty()) flag = false;
  for (size_t i = 1; i < str.size(); ++i) {
    if ((str[i] >= '0') && (str[i] <= '9'))
      a = 1;
    else
      flag = false;

    if ((!std::isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')) {
      flag = false;
    }
  }
  return flag;
}

bool IsInt(const std::string& str) {
  static std::regex r(R"([+-]?\d+)");  // проверяем число ли это в системе
                                       // regular expressions (regex)
  return std::regex_match(str, r);
}

bool IsDouble(const std::string& str) {
  static std::regex r(
      R"([+-]?(\d*\.)?\d+([Ee][+-]?\d+)?)");  // проверяем double число ли это в
                                              // системе regular expressions
                                              // (regex)
  return std::regex_match(str, r);
}

string Parce(const std::string& input) {
  bool Int_test = IsInt(input);
  if (Int_test) {
    return "true";
  std:
    cout << std::stod(input) << std::endl;
  } else
    return "false";
}

int Calculate(const std::string& data) {
  int i = 0;
  int buff_int = 0;
  std::string znak;
  int rez = 0;
  // std::string buff_str;
  vector<int> chisla;
  vector<string> r = SplitString(data);
  for (int i = 0; i < r.size(); ++i) {
    std::cout << i << "element: " << r[i] << '\n';
  }
  for (i = 0; i < data.size(); ++i) {
    if ((data[i] >= '0') && (data[i] <= '9')) {
    }
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
    cout << znak << endl;
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
}

int CalculatePrefix(const std::string& data) {
  cout << "Not Ready" << endl;
  int i = 0;
  int buff_int = 0;
  std::string znak;
  int rez = 0;
  // std::string buff_str;
  vector<int> chisla;
  vector<string> r = SplitString(data);
  for (int i = 0; i < r.size(); ++i) {
    std::cout << i << "element: " << r[i] << '\n';
  }
  for (i = 0; i < data.size(); ++i) {
    if ((data[i] >= '0') && (data[i] <= '9')) {
    }
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
    cout << znak << endl;
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
}
