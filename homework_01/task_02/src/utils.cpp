#include "utils.hpp"
#include <stack>
#include <iostream>
using namespace std;


int Calculate(const std::string& data) 
{
  char oper;
  float num1, num2;
  cout << "Enter an expression like 'number-operation-number' without spaces"<< endl;
  cin >> num1 >> oper >>  num2;
  switch (oper) {
      case '+':
        cout << num1 + num2 << endl;
        break;

      case '-':
        cout << num1 - num2 << endl;
        break;

      case '*':
        cout << num1 * num2 << endl;
        break;

      case '/':
        cout << num1 / num2 << endl;;
        break;

      default:
        cout << "Error! operator is not correct";
        break;
    }

    return 0;

}
