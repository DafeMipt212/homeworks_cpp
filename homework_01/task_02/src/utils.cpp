#include "utils.hpp"
#include <iostream>

double Calculate(const std::string& data) {
    std::stack<char> operation;
    std::stack<double> values;
    Search(data,operation,values);
    while(operation.size() > 0){
        if(!Math(operation, values)){
            return values.top();
        }
    }
    return values.top(); 
}

bool Math(std::stack<char>& operation, std::stack<double>& values){
    double a,b;
    a = values.top();
    values.pop();
    switch (operation.top()) {
        case '-':
            b = values.top();
            values.pop();
            operation.pop();
            values.push(b - a);
            break;
        case '+':
            b = values.top();
            values.pop();
            operation.pop();
            values.push(b + a);
            break;
        case '*':
            b = values.top();
            values.pop();
            operation.pop();
            values.push(b * a);
            break;
        case '/':
            b = values.top();
            if(a==0){
                std::cerr<<"Can't divide by zero";
                return false;
            }
            values.pop();
            operation.pop();
            values.push(b / a);
            break;
        case '^':
            b = values.top();
            values.pop();
            operation.pop();
            values.push(pow(b,a));
            break;
        default:
            return false;
    }
    return true;
}

void Search(std::string str,std::stack<char>& operation, std::stack<double>& values) {
    std::string word;
    int flag = 1;
    for (auto c : str) {
        if (c == '+' || (c == '-' && flag == 0) || c == '*' || c == '/' || c == '^') {
            if(!operation.empty() && Rang(c)<=Rang(operation.top())){
                PushValues(values,word);
                Math(operation,values);
                operation.push(c); 
            }
            else{
                operation.push(c);
            }
        }
        if(c == '('){
            flag = 1;
            operation.push(c);
            continue;
        }
        if(c == ')'){
            PushValues(values,word);
            while(operation.top() != '('){
                if(!Math(operation, values)){
                    return;
                }
            }
            operation.pop();
            continue;
        }
        if (c >= '0' && c <= '9' || c == '.' ||  c == '-' && flag == 1) {
            word += c;
            flag = 0;
        }
        else{
            PushValues(values,word);
        }
    }
    PushValues(values,word);
}

void PushValues(std::stack<double>& values,std::string& word){
    if(!word.empty()){
        values.push(std::stof(word));
        word = "";
    }
}

int Rang(char c){
    if(c == '+' || c == '-')return 1;
    if(c == '*' || c == '/')return 2;
    if(c == '^')return 3;
    return 0;
}
