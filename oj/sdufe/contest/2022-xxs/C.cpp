#include<bits/stdc++.h>

int main(){
  std::vector<std::string> a(8), b(8);
  for(int i = 0; i < 8; i++) std::getline(std::cin, a[i]);
  for(int i = 0; i < 8; i++) std::getline(std::cin, b[i]);
  if(a!= b) std::cout << "YES";
  else std::cout << "NO";
  return 0;
}