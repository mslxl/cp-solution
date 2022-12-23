#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<ll> seq(n);
  for (int i = 0; i < n; i++) {
    std::cin >> seq[i];
  }
  ll min = std::numeric_limits<ll>::max();
  for (int i = 0; i < n; i++) {
    ll v = seq[i];
    min = std::min(min, v);
    for (int j = i + 1; j < n; j++) {
      v &= seq[j];
      min = std::min(min, v);
    }
  }
  std::cout << min;
  return 0;
}
