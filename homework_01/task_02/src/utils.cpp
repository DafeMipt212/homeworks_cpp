#include <iostream>
#include <regex>
#include <stack>
#include "utils.hpp"

bool is_number(const std::string &str) {
    static const std::regex r(R"([+-]?(\d*\.)?\d+([Ee[+-]?\d+)?)");
    return std::regex_match(str, r);
}

int Calculate(const std::string& data) {
    std::vector<int> terms; // хотела сделать тип double, но в тестах int, так что пока так
    std::string tmp;
    std::string number; // пока нигде не используется, скоро будет; исправлю проблему с методом stoi и в целом с логикой
    bool is_brackets = 0;
    bool multipl = 0;
    bool division = 0;
    bool minus = 0;
    
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] != '*' && 
            data[i] != '+' && 
            data[i] != '-' && 
            data[i] != '/' && 
            !(is_number(data[i]))) {
            std::cout << "ошибка!\n";
            return 0;
        }

        if (is_brackets) {
            if (data[i] == ')') {
                int tmp_ans = Calculate(tmp);

                if (multipl) {
                    terms[v1.size()-1] *= tmp_ans;
                    multipl = 0;
                } else if (division) {
                    terms[v1.size()-1] /= tmp_ans;
                    division = 0;
                } else if (minus) {
                    terms.push_back(-tmp_ans);
                    minus = 0;
                } else {
                   terms.push_back(tmp_ans);
                }

                tmp = {};
                is_brackets = 0;
            } else {
                tmp.push_back(data[i]);
            }

            continue;
        }

        if (data[i] == '(') {
            is_brackets = 1;
            continue;
        }

        if (multipl) {
            terms[terms.size()-1] *= std::stoi(data[i]);
            multipl = 0;
            continue;
        }

        if (division) {
            terms[terms.size()-1] /= std::stoi(data[i]);
            division = 0;
            continue;
        }

        if (minus) {
            terms.push_back(-std::stoi(data[i]));
            minus = 0;
            continue;
        }

        if (data[i] == '*') {
            multipl = 1;
            continue;
        }

        if (data[i] == '/') {
            division = 1;
            continue;
        }

        if (data[i] == '-') {
            minus = 1;
            continue;
        }

        if (data[i] == '+') {
            continue;
        }

        terms.push_back(std::stoi(data[i]));
    }

    int answer = 0;

    for (auto n : terms) {
        answer += n;
    }

    return answer;
}
