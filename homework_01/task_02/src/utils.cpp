#include "utils.hpp"
#include <stack>
#include <iostream>
int power (int c, int d)
{   int p = c;
    if (c == 0) {std::cout<<1; return 0;}
    for (int i=1; i<d; i++)
    {
    c*=p;
    }
return c;
}
int factor (int h)
{
    int num=h;
    for (int i=0; i<num; i++)
    {
        h*=--num;
        }
    return h;
}
int logpro (int a, int c)
 {
     int S=1;
     int n=0; 
     while (a>S)
     {
        a = (a/c);
        n++; 
         }
  return n;
 }
float kor(float A, float x)
{
  float xold;
  do
  {
    xold=x;
    x=(x+A/x)/2.0;
  } while (x!=xold);
  return x;
}
int Calculate(const std::string& data) {
    int a = 0;
    int b = 0;
    char operation;
    std::cout << "Введите первое число: ";
    std::cin >> a;
    std::cout << "Введите второе число: ";
    std::cin >> b;
    std::cout << "Введите операцию: ";
    std::cin >> operation;

    switch (operation) {
    case '-':
        std::cout << "a - b = " << a - b << '\n'<<std::endl;
        break;
    case '+':
        std::cout << "a + b = " << a + b << '\n'<<std::endl;
        break;
    case '*':
        std::cout << "a * b = " << a * b << '\n'<<std::endl;
        break;
    case '/':
        std::cout << "a / b = " << a / b << '\n'<<std::endl;
        break;
    case '%':
        std::cout << "a % b = " << a % b << '\n'<<std::endl;
        break; 
    case '&':
        std::cout << "a & b = " << power(a,b) << '\n'<<std::endl; // '&' возведение в степень
        break;   
    case '#':
        std::cout << "a # b = " << logpro(a,b) << '\n'<<std::endl;// '#' вычисление логарифма по основанию b
        break;
    case '@':
        std::cout << "a @ b = " << kor(a,b) << '\n'<<std::endl;// '@' вычисление корня
        break;
    case '!':
        std::cout << "a ! b = " << factor (a) << '\n'<<std::endl;// '!' факториал числа
        break;
            
    default:
        std::cout << "Error\n";
    }
    return 0;
}


 