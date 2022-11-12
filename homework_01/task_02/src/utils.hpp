#pragma once

#include <string>
#include <string_view>
#include <vector>

int Calculate(const std::string& data);
std::vector<std::string> SplitString(const std::string& data);
bool IsInt_bad_version(const std::string& str);
bool IsInt(const std::string& str);
bool IsDouble(const std::string& str);
std::string Parce(const std::string& input);