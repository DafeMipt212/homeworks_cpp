#include "utils.hpp"

#include <stack>

int Calculate(const std::string& data) {
    int a, b, result;
    result = 0;
    a = data[0]-'0';
    b = data[2] - '0';
    switch (data[1]){
    case ('+'):
        result = a + b;
        return result; 
    case ('-'):
        result = a - b;
        return result; 
    case ('*'):
        result = a * b;
        return result; 
    case ('/'):
        result = a / b;
        return result; 
    }
    return 0;
}