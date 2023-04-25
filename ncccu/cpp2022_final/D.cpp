#include<bits/stdc++.h>
std::map<std::string, int> collect;
int main(){
  std::string item;
  while(std::getline(std::cin, item, ',')){
    collect[item]++;
  }
  for(auto item: collect){
    std::cout << item.first << " " << item.second << "\n";
  }
  return 0;
}
