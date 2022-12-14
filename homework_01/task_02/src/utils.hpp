#pragma once

#include <string>
#include <vector>
#include <stack>
#include <cmath>
double Calculate(const std::string& data);
void Search(std::string str,std::stack<char>& operation, std::stack<double>& values);
int Rang(char c);
bool Math(std::stack<char>& operation, std::stack<double>& values);
void PushValues(std::stack<double>& values,std::string& word);
