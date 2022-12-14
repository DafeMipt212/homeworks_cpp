#include "utils.hpp"

#include <stack>
#include <iostream>
#include <vector>
using namespace std;

vector <string> SplitString(string& s) {
    s += " ";
    string s1 = "";
    char* ptr = &(s[0]);
    vector <string> v;

    while(*ptr != '\0'){
        if ((*ptr == ' ') or (*ptr == '\t')) {
            if (s1 != "") v.push_back(s1);
            s1 = "";
        }
        else {
            s1 += *ptr;
            }
        ++ptr;
        }
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << endl;} 
    return v;
  //return {data};
}

int main(){
    string s;    
    getline(cin, s);
    SplitString(s);
}