#include <bits/stdc++.h>
#include <limits>
#include <numeric>
using ll = long long;
void solve() {
  int n;
  std::cin >> n;
  std::vector<ll> seq(n);
  for (int i = 0; i < n; i++)
    std::cin >> seq[i];

  auto min = std::accumulate(
      seq.begin(), seq.end(), std::numeric_limits<ll>::max(),
      [](const ll &lhs, const ll &rhs) { return std::min(lhs, rhs); });
      if(seq[0] == min) std::cout << "Bob\n";
      else std::cout << "Alice\n";
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}