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
    double a,b,c;
    a = values.top();
    values.pop();
    switch (operation.top()) {
        case '-':
            b = values.top();
            values.pop();
            operation.pop();
            c = b - a;
            values.push(c);
            break;
        case '+':
            b = values.top();
            values.pop();
            operation.pop();
            c = b + a;
            values.push(c);
            break;
        case '*':
            b = values.top();
            values.pop();
            operation.pop();
            c = b * a;
            values.push(c);
            break;
        case '/':
            b = values.top();
            if(a==0){
                std::cerr<<"Can't divide by zero";
                return false;
            }
            values.pop();
            operation.pop();
            c = b / a;
            values.push(c);
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
        if (c == '+' || (c == '-' && flag == 0) || c == '*' || c == '/') {
            if(!operation.empty() && Rang(c)<=Rang(operation.top())){
                values.push(std::stof(word));
                word = "";
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
            values.push(std::stof(word));
            word = "";
            while(operation.top() != '('){
                if(!Math(operation, values)){
                    return;
                }
            }
            operation.pop();
            continue;
        }
        if (c != '+' && c != '-' && c != '*' && c != '/' ||  c == '-' && flag == 1) {
            word += c;
            flag = 0;
        }
        else if (!word.empty()) {
            values.push(std::stof(word));
            word = "";
        }
    }
    if (!word.empty()){
        values.push(std::stod(word));
    }
}
int Rang(char c){
    if(c == '(' || c == ')')return 0;
    if(c == '+' || c == '-')return 1;
    if(c == '*' || c == '/')return 2;
    return 0;
}
