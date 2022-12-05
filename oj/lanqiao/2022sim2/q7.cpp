#include<iostream>
#include<string>
#include<set>

int main(){
  int n;
  std::cin >> n;
  std::set<std::string> v;

  for(int i = 0; i < n; i++){
    std::string w;
    std::cin >> w;
    if(!v.count(w)){
      std::cout << w << "\n";
      v.insert(w);
    }
  }
  return 0;
}