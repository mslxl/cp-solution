#include <string>
using namespace std;

string solution(int number){
  int  values [] ={1000,900,500,400,100,90,50,40,10,9,5,4,1};
  string symbol [13] ={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
  int currentNumber=number;
  string str="";
  for(int i=0;i<13;i++){
    if(currentNumber>=values[i]){
      int i_count=currentNumber/values[i];
      currentNumber=currentNumber%values[i];
      for(int j=0;j<i_count;j++)
      {
        str+=symbol[i];
      }
    }
  }
  return str;
}
