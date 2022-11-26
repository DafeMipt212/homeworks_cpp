#include "utils.hpp"
#include <stack>
#include <iostream>
using namespace std;



int Calculate(const std::string& data) {
  char oper = data[1];
  char n1 = data[0];
  char n2 = data[2];
  int num1 = n1 - 48;
  int num2 = n2 - 48;
  int result;
  switch (oper) {
      case '+':
        result = num1 + num2;
        break;

      case '-':
        result = num1 - num2;
        break;

      case '*':
        result = num1 * num2;
        break;

       case '/':
        if (num2 == 0){
          result=2147483647;
        }
        else{
          result = (int)num1 / num2;
        }
        break;
      default:
        cout << "Error! operator is not correct";
        break;

    }
return result;
}