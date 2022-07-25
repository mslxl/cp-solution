#include <bits/stdc++.h>
#include <cstdint>

void solve() {
  int T;
  std::cin >> T;
  std::vector<std::string> str(T);
  unsigned long long minl = INT32_MAX, maxl = 0;
  for (int i = 0; i < T; i++) {
    std::cin >> str[i];
    minl = std::min(minl, str[i].size());
    maxl = std::max(maxl, str[i].size());
  }
  std::set<std::string> set(str.begin(), str.end());
  for (const auto &toj : str) {
    bool found = false;
    for(int i = minl; i < toj.size(); i++){
        if(set.count(toj.substr(0,i)) && set.count(toj.substr(i))){
            found = true;
            break;
        }
    }
    std::cout << (int)found;
  }
  std::cout << std::endl;
}
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}