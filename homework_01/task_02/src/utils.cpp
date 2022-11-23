#include "utils.hpp"

#include <stack>

int Calculate(const std::string& data) {
  return fanc(searchOperation(data),splitSpring(data));
}

std::vector<std::string> splitSpring(std::string str) {
    std::vector<std::string> res;
    std::string word;
    std::string sign;
    for (auto c : str) {
        if (c != '+' && c != '-' && c != '*' && c != '/') {
            word += c;
        }
        else if (!word.empty()) {
            res.push_back(word);
            word = "";
        }
    }
    res.push_back(word);
    return res;
}

char searchOperation(std::string str) {
    std::vector<std::string> res;
    std::string word;
    std::string sign;
    for (auto c : str) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            return c;
        }
    }
    return '+';
}

int fanc(char operation, std::vector<std::string> res) {
    switch (operation) {
    case '-':
        return std::stoi(res[0]) - std::stoi(res[1]);
        break;
    case '+':
        return std::stoi(res[0]) + std::stoi(res[1]);
        break;
    case '*':
        return std::stoi(res[0]) * std::stoi(res[1]);
        break;
    case '/':
        return std::stoi(res[0]) / std::stoi(res[1]);
        break;
    default:
        return 0;
    }
}
