#include <bits/stdc++.h>
#ifdef Local
#define tout \
  if (1)     \
  std::cerr
#else
#define tout \
  if (0)     \
  std::cerr
#endif
using ll = long long;
#define rep(i, s, e) for (int i = s; i < e; i++)

void solve() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << "0" << std::endl;
    return;
  }
  std::vector<ll> seq(n);
  rep(i, 0, n) std::cin >> seq[i];
  std::sort(seq.begin(), seq.end());
  ll sum = 0;
  rep(i, 1, n){
    sum += (seq[0] + seq[i]);
  }
  std::cout << sum << std::endl;
  return;
}

int main() {
#ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}