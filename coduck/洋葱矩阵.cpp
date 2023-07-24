#include <bits/stdc++.h>

void solve();
int main() {

  int T;
  std::cin >> T;
  while (T--)
    solve();
  return 0;
}

using ll = long long;
#define int ll
void solve() {
  int k;
  std::cin >> k;
  int pos_value = 1;
  for (int i = 1;; pos_value += (2 * i), i++) {
    int coor = i;
    int minbound = pos_value - coor;
    int maxbound = pos_value + coor;
    if (minbound < k && maxbound > k) {
      if (k == pos_value) {
        std::cout << coor << " " << coor << "\n";
      } else if (k < pos_value) {
        std::cout << (coor - (pos_value - k)) << " " << coor << "\n";
      } else {
        std::cout << coor << " " << (coor - (k - pos_value)) << "\n";
      }
      return;
    }
  }
}