#include "utils.hpp"

#include <iostream>
#include <regex>
#include <stack>

bool is_number(const std::string &str) {
    static const std::regex r(R"([+-]?(\d*\.)?\d+([Ee[+-]?\d+)?)");
    return std::regex_match(str, r);
}

int Calculate(const std::string& data) {
    std::vector<int> terms;
    std::string tmp;
    std::string number;
    bool is_brackets = 0;
    int tmp_brackets = 0;
    bool multipl = 0;
    bool division = 0;
    bool minus = 0;
    
    for (size_t i = 0; i < data.size(); ++i) {
        if (is_brackets) {
            if (data[i] == ')') {
                if (tmp_brackets) {
                    tmp += data[i];
                    tmp_brackets -= 1;
                    continue;
                }

                try {
                    int tmp_ans = Calculate(tmp);
   
                    if (multipl) {
                        terms[terms.size() - 1] *= tmp_ans;
                        multipl = 0;
                    } else if (division) {
                        terms[terms.size() - 1] /= tmp_ans;
                        division = 0;
                    } else if (minus) {
                        terms.push_back(-tmp_ans);
                        minus = 0;
                    } else {
                       terms.push_back(tmp_ans);
                    }

                    tmp = "";
                    is_brackets = 0;
                } catch (std::string error) {
                    throw (error);
                }
            } else {
                if (data[i] == '(') {
                    tmp_brackets += 1;
                }

                tmp += data[i];
            }

            continue;
        }

        if (data[i] != '*' && 
            data[i] != '+' && 
            data[i] != '-' && 
            data[i] != '/' &&
            data[i] != '(' &&
            data[i] != ')') {
            number += data[i];
            continue;
        }

        if (data[i] == '(') {
            is_brackets = 1;
            continue;
        }

        if (!is_number(number)) {
            throw ("ошибка!\n");
        }

        if (!number.empty()) {
            if (multipl) {
                terms[terms.size() - 1] *= std::stoi(number);
                multipl = 0;
            } else if (division) {
                terms[terms.size() - 1] /= std::stoi(number);
                division = 0;
            } else if (minus) {
                terms.push_back(-std::stoi(number));
                minus = 0;
            } else {
                terms.push_back(std::stoi(number));
            }
        }

        if (data[i] == '*') {
            multipl = 1;
        }

        if (data[i] == '/') {
            division = 1;
        }

        if (data[i] == '-') {
            minus = 1;
        }

        number = "";
    }

    if (!number.empty()) {
        if (multipl) {
            terms[terms.size() - 1] *= std::stoi(number);
            multipl = 0;
        } else if (division) {
            terms[terms.size() - 1] /= std::stoi(number);
            division = 0;
        } else if (minus) {
            terms.push_back(-std::stoi(number));
            minus = 0;
        } else {
            terms.push_back(std::stoi(number));
        }
    }

    int answer = 0;

    for (auto n : terms) {
        answer += n;
    }

    return answer;
}
