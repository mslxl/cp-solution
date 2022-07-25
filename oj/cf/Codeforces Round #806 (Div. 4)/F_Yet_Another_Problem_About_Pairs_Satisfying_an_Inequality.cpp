#include <algorithm>
#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> seq;
  for (int i = 1; i <= n; i++) {
    int v;
    std::cin >> v;
    if (v < i)
      seq.push_back(std::make_pair(v, i));
  }
  std::sort(seq.begin(), seq.begin(),
            [](std::pair<int, int> l, std::pair<int, int> r) -> bool {
              return l.second < r.second;
            });
  long long res = 0;
  for (const auto &p : seq) {
    res += std::lower_bound(
               seq.begin(), seq.end(), std::make_pair(p.second, p.first),
               [](std::pair<int, int> l, std::pair<int, int> r) -> bool {
                 return l.second < r.second;
               }) -
           seq.begin();
  }
  std::cout << res << std::endl;
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}