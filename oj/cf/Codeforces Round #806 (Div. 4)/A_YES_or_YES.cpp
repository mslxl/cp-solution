#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>

int main() {
  std::string line;
  int T;
  std::cin >> T;
  while(T--){
    std::cin >> line;
    for(auto& c:line){
        c = tolower(c);
    }
    if(line == "yes"){
        std::cout << "YES" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
  }
  return 0;
}