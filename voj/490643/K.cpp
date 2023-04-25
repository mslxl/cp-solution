#include<bits/stdc++.h>
#define rep(i, s, e) for (int i = s; i < e; i++)

const int maxm = 60;
struct q {
  int a;
  int b;
  int t;
} p[maxm];

void solve() {
  int m;
  std::cin >> m;
  rep(i, 1, m + 1) {
    std::cin >> p[i].a;
    p[i].t = 3 * p[i].a;
  }
  rep(i, 1, m + 1) {
    std::cin >> p[i].b;
  }

  int i;
  for (i = 1; i <= m; i++) {
    if (p[i].b > p[i].t)
      break;
  }

  if (i <= m)
    std::cout << i << std::endl;
  else
    std::cout << -1 << std::endl;
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}