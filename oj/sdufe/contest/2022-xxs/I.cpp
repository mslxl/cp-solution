#include <bits/stdc++.h>

void dfs(std::vector<std::pair<int, int>> &vec,
         std::vector<std::pair<int, int>>::iterator beg) {
  if (beg == vec.end()) {
    return;
  }
  if(vec.size() == 1){
    vec.clear();
    return;
  }
  auto last = *beg;
  beg = vec.erase(beg);
  auto cur = *beg;
  if (cur.first >= last.first && cur.second >= last.second){
    dfs(vec, beg);
  }
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> m;
  for (int i = 0; i < n; i++) {
    int a, b;
    std::cin >> a;
    std::cin.get();
    std::cin >> b;
    m.emplace_back(std::make_pair(std::max(a, b), std::min(b, a)));
  }
  std::sort(m.begin(), m.end());
  int ans = 0;
  while (!m.empty()) {
    ans++;
    dfs(m, m.begin());
  }
  std::cout << ans << std::endl;
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}