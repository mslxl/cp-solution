#include <bits/stdc++.h>
#include <sstream>
void solve() {
  int n;
  std::cin >> n;
  std::string line;
  std::getline(std::cin, line);
  std::getline(std::cin, line);
  std::stringstream ss;
  ss << line;
  ss >> n;
  if(n == 1){
    std::cout << "Yes\n";
  }else{
    std::cout << "No\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}