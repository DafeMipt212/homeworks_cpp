#include "utils.hpp"

#include <stack>
#include <iostream>
#include <vector>
using namespace std;

vector <string> SplitString(string& s){
    s += " ";
    string CurrentString = "";
    char* ptr = &(s[0]);
    vector <string> data;

    while(*ptr != '\0'){
        if (*ptr == '(') {
            while((*ptr != ')') && (*ptr != '\0')){
                CurrentString += *ptr;
                ++ptr;
            }
            CurrentString += *ptr;
            ++ptr;
            data.push_back(CurrentString);
            CurrentString = "";
        }
        if ((*ptr == ' ') || (*ptr == '\t')) {
            if (CurrentString != "") data.push_back(CurrentString);
            CurrentString = "";
        }
        else {
            CurrentString += *ptr;
            }
        ++ptr;
    }    
    for(int i = 0; i < data.size(); ++i){
        cout << data[i] << endl;} 
    return data;
    }