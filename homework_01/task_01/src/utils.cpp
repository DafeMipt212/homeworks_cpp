#include "utils.hpp"

#include <stack>
#include <iostream>
#include <vector>

using namespace std;

vector <string> SplitString(const string& s){
    
    string Current_String = "";
    const char* ptr = &(s[0]);
    vector <string> result;

    while(*ptr != '\0'){
        if (*ptr == '(') {
            while((*ptr != ')') && (*ptr != '\0')){
                Current_String += *ptr;
                ++ptr;
            }
            Current_String += *ptr;
            ++ptr;
            result.push_back(Current_String);
            Current_String = "";
        }
        if ((*ptr == ' ') || (*ptr == '\t')) {
            if (Current_String != "") result.push_back(Current_String);
            Current_String = "";
        }
        else {
            Current_String += *ptr;
        }
        ++ptr;
    }    

    return result;
}