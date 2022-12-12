#include <iostream>
#include <string>
#include <vector>
#define vector_string std::vector<std::string>

vector_string split_string(const std::string &s) {
    vector_string vec;
    std::string tmp = "";

    for (auto c : s) {
        if (c != ' ') {
            tmp += c;
            continue;
        }

        if (tmp != "") {
            vec.push_back(tmp);
            tmp = "";
        }
    }

    if (tmp != "") {
        vec.push_back(tmp);
    }

    return vec;
}
