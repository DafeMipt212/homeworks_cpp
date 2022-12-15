#include "utils.hpp"

#include <stack>
#include <iostream>
#include <vector>
using namespace std;

int Calculate(string& str) {
    str += " ";
    string CurrentString = "";
    char* ptr = &(str[0]);
    vector <string> data;

    while(*ptr != '\0'){
        if ((*ptr == '+') ||(*ptr == '-')||(*ptr == '*')||(*ptr == '/')) {
            if (CurrentString != ""){ 
            data.push_back(CurrentString);
            CurrentString = "";
            }
            CurrentString += *ptr;
            data.push_back(CurrentString);
            CurrentString = "";
            ++ptr;
            }

        CurrentString += *ptr;
        ++ptr;
    }
    data.push_back(CurrentString);
    
    int a = stoi(data[0]);
    int b = stoi(data[2]);

    if (data[1] == "+") {return a + b;}
    else if (data[1] == "-") {return a - b;}
    else if (data[1] == "*") {return a * b;}
    else if (data[1] == "/") {return a / b;}
    else return 0;
}