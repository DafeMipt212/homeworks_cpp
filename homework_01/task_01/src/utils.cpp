#include "utils.hpp"

#include <iostream>
#include <stack>
#include <regex>
#include <vector>

using namespace std;

std::vector<std::string> SplitString(const std::string& data) {
  vector<string> result;
  string  str  =  data;    
  size_t  pos  =  0;      
  while  (pos=str.find(" ") != string::npos)  
  {
    if(str == " " || str == ""){
      break;
    }
    if(str[0] == ' '){
      str = str.substr(1);
      continue;
    }
    if(pos < str.find("(") && pos < str.find("\t")){
      result.push_back(str.substr(0,  pos));     
      str.erase(0,  pos + 1);
    }
    else if((pos = str.find("\t")) < str.find("(")){
      result.push_back(str.substr(0,  pos));     
      str.erase(0,  pos + 1);
    }
    else if((pos=str.find("(")) != string::npos){
      result.push_back(str.substr(pos,  str.find(")")+1));     
      str.erase(pos,  str.find(")") + 1);
    }
  }
  if(str != " " && str != ""){
    result.push_back(str.substr(0,  pos)); 
  }
  return result;
}  