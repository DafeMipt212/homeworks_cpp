#include <string.h>

#include <iostream>
#include <regex>
#include <stack>
#include <utils.hpp>
using namespace std;
int main() {
  cout << "Itog:" << endl;
  cout << Calculate("8/0") << endl;
  cout << Calculate("8 / 0") << endl;
  return 0;
}
