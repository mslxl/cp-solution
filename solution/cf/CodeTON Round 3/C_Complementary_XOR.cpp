#include <bits/stdc++.h>
#include <numeric>

template <typename T = int> constexpr T norm(T x) { return x < 0 ? 0 : x; }

#include <array>
#include <iostream>
#include <type_traits>
#include <vector>


const int maxn = 2e5;

void solve() {
  int n;
  std::cin >> n;
  std::string a, b;
  std::getline(std::cin, a);
  std::getline(std::cin, a);
  std::getline(std::cin, b);

  bool refilp = false;
  if (a != b) {
    refilp = true;
    for (auto &ch : a) {
      ch = '1' - ch + '0';
    }
    if (a != b) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
  std::vector<std::pair<int,int>> ops;
  std::vector<int> cnt(n+ 17);
  if(refilp){
    ops.push_back({1,n});
  }
  if(a[0] == '1'){
    ops.push_back({1,n});
    ops.push_back({2,n});
  }
  for(int i = 1; i < n; i++){
    if(a[i] == '1'){
      cnt[i+1]++;
      cnt[i]++;
    } 
  }
  for(int i = 1; i < n+1; i++){
    if(cnt[i] % 2 != 0){
      ops.push_back({1, i});
    }
  }
  std::cout << ops.size() << "\n";
  for(auto&p: ops){
    std::cout << p.first << " " << p.second << "\n";
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