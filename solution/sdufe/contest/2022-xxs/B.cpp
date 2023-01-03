#include<bits/stdc++.h>
int main(){
  std::string a,b;
  std::getline(std::cin, a);
  std::getline(std::cin, b);
  std::unordered_map<char, long long> map;
  for(auto i : b){
    map[i]++;
  }
  for(auto i : a){
    map[i]--;
    if(map[i] < 0){
      std::cout << "NO";
      return 0; 
    }
  }
  std::cout << "YES";
  return 0;
}