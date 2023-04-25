// 简单的数学题
#include <bits/stdc++.h>
#include <unordered_map>

// S + 1 = (a + 1) (b + 1)

// S + 1 = c * d  (c>=1 && d >= 1)

std::unordered_map<int, int> map;

using ll = unsigned long long;
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int k;
    std::cin >> k;

    if (k == 0) {
      std::cout << 1 << "\n";
      continue;
    } else if (map.count(k)) {
      std::cout << map[k] << "\n";
      continue;
    }

    ll ans = 0;
    ll lim = std::sqrt(k+1);
    for (int c = 1; c <= lim; c++) {
      if ((k + 1) % c == 0 && (k + 1) / c > 0) {
        ans += 2;
        if (c * c == k + 1) {
          ans--;
        }
      }
    }
    map[k] = ans;
    std::cout << ans << "\n";
  }

  return 0;
}