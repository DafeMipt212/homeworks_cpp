#include "utils.hpp"

#include <stack>

int Calculate(const std::string& data) {
  char operation = SearchOperation(data);
  std::vector<std::string> values = SearchValues(data);
  switch (operation) {
    case '-':
        return std::stoi(values[0]) - std::stoi(values[1]);
        break;
    case '+':
        return std::stoi(values[0]) + std::stoi(values[1]);
        break;
    case '*':
        return std::stoi(values[0]) * std::stoi(values[1]);
        break;
    case '/':
        return std::stoi(values[0]) / std::stoi(values[1]);
        break;
    default:
        return 0;
    }
}

std::vector<std::string> SearchValues(std::string str) {
    std::vector<std::string> result;
    std::string word;
    for (auto c : str) {
        if (c != '+' && c != '-' && c != '*' && c != '/') {
            word += c;
        }
        else if (!word.empty()) {
            result.push_back(word);
            word = "";
        }
    }
    result.push_back(word);
    return result;
}

char SearchOperation(std::string str) {
    for (auto c : str) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            return c;
        }
    }
    return '+';
}
