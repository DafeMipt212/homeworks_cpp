#include <iostream>
#include <sstream>
#include <utils.hpp>
using namespace std;

int main() {
    using namespace std;
    while (!cin.eof()) {
        cout << "Expression: ";
        string line;
        getline(cin, line);
        if (!line.empty()) {
            auto res = Сalculate(line);
            cout << "Result is " << res << endl;
        }
    }
}
