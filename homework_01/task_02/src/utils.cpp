#include "utils.hpp"
#include <sstream>
#include <iostream>
using namespace std;

int readNumber(istringstream& ss) {
    int res;
    ss >> res;
    if (ss.fail()) {
        throw std::runtime_error("Number expected here");
    }
    return res;
}

bool isMultDiv(char op) {
    return op == '*' || op == '/';
}

int evaluateMultDiv(istringstream& ss) {
    auto res = readNumber(ss);
    while (ss.good()) {
        char op;
        ss >> op;
        if (!isMultDiv(op)) {
            ss.putback(op);
            return res;
        }
        auto right = readNumber(ss);
        switch (op) {
            case '*': res *= right; break;
            case '/': res /= right; break;
            default: throw std::runtime_error("Unexpected operator here");
        }
    }
    return res;
}

int Сalculate(string expr) {
    istringstream ss(expr);
    auto res = evaluateMultDiv(ss);
    while (ss.good()) {
        char op;
        ss >> op;
        auto right = evaluateMultDiv(ss);
        switch (op) {
            case '+': res += right; break;
            case '-': res -= right; break;
            default: throw std::runtime_error("Unexpected operator here");
        }
    }
    return res;
}