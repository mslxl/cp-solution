#pragma optimtize(2)
#include<bits/stdc++.h>

int main(){
  int inp;
  std::cin >> inp;
  std::string n = "0123456789";
  do{
    int n1 = std::atoi(n.substr(0, 5).data());
    int n2 = std::atoi(n.substr(5, 5).data());
    if(n1  == inp * n2){
      std::cout << n.substr(0, 5) << " / " << n.substr(5, 10) << " = " << inp << "\n";
    }
  }while(std::next_permutation(n.begin(), n.end()));

}