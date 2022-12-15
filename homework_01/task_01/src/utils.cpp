#include "utils.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>

typedef int typevec;
typedef std::vector<typevec> ValueVec;
 
ValueVec& SplitString(const std::string &s, char dels, ValueVec&elems)
{
    std::stringstream srw(s);
    std::string item;
    while(std::getline(srw, item, dels))
    {
        elems.push_back(std::stoi(item));
    }
    return elems;
}
 
ValueVec SplitString(const std::string &str, char dels)
{
    ValueVec elems;
    SplitString(str, dels, elems);
    return elems;
}
 

 