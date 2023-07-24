#include <bits/stdc++.h>

void solve();

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}

void solve() {
  int n, k;
  std::cin >> n >> k;
  if (k > n * n) {
    std::cout << "-1\n";
    return;
  }
  if((n-1)/2 + 1 < k){
    std::cout << "-1\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j && (i - 1) % 2 == 0 && k != 0) {
        std::cout << 'R';
        k--;
      } else {
        std::cout << '.';
      }
    }
    std::cout << "\n";
  }
}