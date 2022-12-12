#include <iostream>
#include <string>
#include <vector>
#include <regex>
#define vector_string std::vector<std::string>

bool is_numb(const std::string &str) {
    static const std::regex r(R"([+-]?(\d*\.)?\d+([Ee[+-]?\d+)?)");
    return std::regex_match(str, r);
}

std::string calculate(vector_string v) {
    std::vector<double> v1;
    vector_string tmp;
    bool f = 0, pr = 0, dl = 0, mns = 0;
    
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] != "*" && v[i] != "+" && v[i] != "-" && v[i] != "/" && !(is_numb(v[i]))) {
            return "ошибка!\n";
        }

        if (f) {
            if (v[i] == ")") {
                double tmp_ans = calculate(tmp);

                if (pr) {
                    v1[v1.size()-1] *= tmp_ans;
                    pr = 0;
                } else if (dl) {
                    v1[v1.size()-1] /= tmp_ans;
                    dl = 0;
                } else if (mns) {
                    v1.push_back(-tmp_ans);
                    mns = 0;
                } else {
                   v1.push_back(tmp_ans);
                }

                tmp = {};
                f = 0;
            } else {
                tmp.push_back(v[i]);
            }

            continue;
        }

        if (v[i] == "(") {
            f = 1;
            continue;
        }

        if (pr) {
            v1[v1.size()-1] *= std::stod(v[i]);
            pr = 0;
            continue;
        }

        if (dl) {
            v1[v1.size()-1] /= std::stod(v[i]);
            dl = 0;
            continue;
        }

        if (mns) {
            v1.push_back(-std::stod(v[i]));
            mns = 0;
            continue;
        }

        if (v[i] == "*") {
            pr = 1;
            continue;
        }

        if (v[i] == "/") {
            dl = 1;
            continue;
        }

        if (v[i] == "-") {
            mns = 1;
            continue;
        }

        if (v[i] == "+") {
            continue;
        }

        v1.push_back(std::stod(v[i]));
    }

    double answer = 0;

    for (auto n : v1) {
        answer += n;
    }

    std::cout << answer << '\n';
    return "\n";
}
