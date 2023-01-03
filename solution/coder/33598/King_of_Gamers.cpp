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

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  double x = a/b;

  std::cout << std::ceil(n * x);


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