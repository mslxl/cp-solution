#include<bits/stdc++.h>

using ll = long long;
using ul = unsigned long long;
using ld = long double;

void solve(const std::size_t testcase){
  int n;
  std::string wd;
  std::cin >> n >> wd;
  char max = 0;
  for(auto& ch: wd){
    max = std::max(max, ch);
  }
  std::cout << max - 'a' + 1 << "\n";
}

int main(){

	int t;
  std::cin >> t;
  for(std::size_t i = 1; i <= t; i++){
  	solve(t);
  }

	return 0;
}