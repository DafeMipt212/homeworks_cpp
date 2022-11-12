#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
#include <string>
#include <utils.hpp>
#include <regex>
using namespace std;
int main() {
  /*std::string data;
  std::getline(std::cin, data);
  std::cout << Calculate(data);
  return 0;*/
 //eherh832759328623626
string input;
int res;
while(7){
  
  std::cout << "Vvedite, poghaluista, stroku: " << std::endl;
  getline(cin,input);
  if (input=="quit")
  {
    break;
  }
  cout<<Parce(input)<<endl;
  cout<<"Double: "<<IsDouble(input)<<endl;
  //res=SplitString(s);
  //cout<<Calculate(input)<<endl;
}
return 0;

}
