#include <string.h>

#include <iostream>
#include <regex>
#include <stack>
#include <utils.hpp>
using namespace std;
int main() {
  string input;
  int res;
  cout << "REZULTAT" << Calculate("5*9-8") << endl;
  while (7) {
    std::cout << "Vvedite, poghaluista, stroku: " << std::endl;
    getline(cin, input);
    if (input == "quit") {
      break;
    }
    cout << Parce(input) << endl;
    cout << "Double: " << IsDouble(input) << endl;
  }
  return 0;
}
