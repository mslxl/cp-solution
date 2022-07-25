#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;

  unsigned long long sum = 0;
  unsigned long long ops = -1;

  for (int i = 0; i < n; i++) {
    int t;
    std::cin >> t;
    if (t % 2 == 0) {
      sum += t;
      ops++;
    }
  }
  while (sum % 2 == 0) {
    sum /= 2;
    ops++;
  }
  std::cout << ops << std::endl;
}
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
