#include "utils.hpp"

#include <stack>

auto split_string(const std::string &str){
    std::vector<char> braces;
    std::vector<std::string> res;
    std::string temp;
    for (auto c : str){
        if (c!=' '){
            temp+=c;
        }
        else if (braces.size()!=0){
            temp+=c;
        }
        else if (!temp.empty()){
            res.push_back(temp);
            temp.clear();
        }
        if (c == '('){
            braces.push_back(c);
        }
        else if ((braces.size()>0) && (c == ')')){
            if (braces.back() == '('){
                braces.pop_back();
            }
        }
    }
    if (!temp.empty()){
        res.push_back(temp);
    }
    return res;
}

std::string prep_string(std::string str){
    auto vect = split_string(str);
    std::string temp_str;
    for (auto i : vect){
        temp_str += i;
    }

    std::string final_str;

    for (char i : temp_str){
        if ((i=='*') || (i=='/') || (i=='-') || (i=='+')){
            final_str += ' '; final_str += i; final_str += ' ';
        }
        else{
            final_str += i;
        }
    }
    return final_str;
}

float conductor(std::vector<float> values, std::vector<char> flags, int num_of_operations){
    int i = 0;
    std::vector<float> final_vals;
    int index = 0;
    float temp_value = 0;
    while (num_of_operations > 0){
        // * /
        for (int i = 0; i < flags.size(); ++i){
            if ((flags.at(i) == '*') || (flags.at(i) == '/')){
                if (flags.at(i) == '*'){
                    temp_value = values.at(i-1)*values.at(i+1);
                }
                else{
                    temp_value = values.at(i-1)/values.at(i+1);
                }
                
                values.erase(values.begin() + i-1, values.begin() + i+2);
                values.insert(values.begin() + i-1, temp_value);

                flags.erase(flags.begin() + i-1, flags.begin() + i+2);
                flags.insert(flags.begin() + i-1, '~');
            
                final_vals.push_back(temp_value);
                num_of_operations -= 1;
            }
        }
        // + -
        for (int i = 0; i < flags.size(); ++i){
            if ((flags.at(i) == '+') || (flags.at(i) == '-')){
                if (flags.at(i) == '+'){
                    temp_value = values.at(i-1) + values.at(i+1);
                    //std::cout << "this: " << temp_value << std::endl;
                }
                else{
                    temp_value = values.at(i-1)-values.at(i+1);
                }

                values.erase(values.begin() + i-1, values.begin() + i+2);
                values.insert(values.begin() + i-1, temp_value);

                flags.erase(flags.begin() + i-1, flags.begin() + i+2);
                flags.insert(flags.begin() + i-1, '~');

                final_vals.push_back(temp_value);
                num_of_operations -= 1;
            }
        }
    }
    return values.at(0);
}



std::string brace_clipper(std::string str){
    std::string f_str;
    for (int i = 1; i < str.size()-1; ++i){
        f_str+=str[i];
    }
    return f_str;
}


//calculator
float Calculate(const std::string &str){
    auto vect = split_string(str);
    float result = 0;
    std::vector<float> values;
    std::vector<char> flags;
    int num_of_operations = 0;


    for (int i = 0; i < vect.size(); ++i){
        std::string el = vect.at(i);
        
        //braces
        if ((el[0] == '(') || (el[0] == '{') || (el[0] == '[')){
            values.push_back(Calculate(brace_clipper(el)));
            flags.push_back('~');
        }
        //other cases
        else if ((el[0] == '+') || (el[0] == '-') || (el[0] == '*') || (el[0] == '/')){
            flags.push_back(el[0]);
            values.push_back(0);
            num_of_operations += 1;
        }
        else{
            values.push_back(std::stof(el));
            flags.push_back('~');
        }
    }
    return conductor(values, flags, num_of_operations);
}