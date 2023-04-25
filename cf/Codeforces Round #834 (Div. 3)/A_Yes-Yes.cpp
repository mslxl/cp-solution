#include <bits/stdc++.h>

using ll = long long;
using ul = unsigned long long;
using ld = long double;

void solve(const std::size_t testcase) {
  std::string line;
  std::cin >> line;
  std::set<std::string> canNot = {"Yes", "es", "sY"};
  if(line.size() < 2){
    if(line[0] == 'Y' || line[0] == 'e' || line[0] == 's' ){
      std::cout << "YES\n";
      return;
    }else{
      std::cout << "NO\n";
      return;
    }
  }else
  for(int i = 0; i < line.size()-1; ){
      if(line[i] == 'Y' && line[i+1] == 'e'){
        i++;
      }else if(line[i] == 'e' && line[i+1] == 's'){
        i++;
      }else if(line[i] == 's' && line[i+1] == 'Y'){
        i++;
      }else{
        std::cout << "NO\n";
        return;
      }
  }
  std::cout << "YES\n";
  return;
}

int main() {

  int t;
  std::cin >> t;
  for (std::size_t i = 1; i <= t; i++) {
    solve(t);
  }

  return 0;
}