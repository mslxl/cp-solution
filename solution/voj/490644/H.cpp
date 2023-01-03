#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = s; i < e; i++)
#define fors(i, s, e) rep(i, s, e + 1)
using ll = long long;
const int maxn = 1e5 + 5;
void solve() {
  ll note[maxn];
  int n;
  std::cin >> n;
  fors(i, 1, n) std::cin >> note[i];

  std::vector<int> crack;

  rep(i, 2, n) {
    if (note[i] > note[i - 1] && note[i] > note[i + 1])
      crack.push_back(i);
  }
  int flag = 0;

  rep(i, 1, crack.size()) {
    if (crack[i] - crack[i - 1] == 2) {
      int p = crack[i];
      if (note[p] == note[p - 2])
        flag = 2;
      else
        flag = std::max(flag, 1);
    }
  }
  if (!flag) {
    rep(i, 0, crack.size()) {
      int p = crack[i];
      if (p == 2 || p == n - 1 || (p - 2 >= 1 && note[p - 2] == note[p]) ||
          (p + 2 <= n && note[p + 2] == note[p]))
        flag = 1;
    }
  }
  std::cout << (crack.size() - flag) << std::endl;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}