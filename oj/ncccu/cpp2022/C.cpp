#include <bits/stdc++.h>
const int maxn = 1000 + 17;

struct Cake {
  int p, s;
} c[maxn];

struct Cmp {
  bool operator()(const Cake &lhs, const Cake &rhs) {
    if (lhs.p + lhs.s != rhs.p + rhs.s) {
      return lhs.p + lhs.s < rhs.p + rhs.s;
    } else {
      return lhs.p < rhs.p;
    }
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++)
    std::cin >> c[i].p >> c[i].s;
  std::sort(c, c + n, Cmp());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int totalCost = std::ceil(1.0 * c[i].p / 2) + c[i].s;
    if (totalCost > m)
      continue;
    int numBuy = 1;

    for (int j = 0; j < n; j++) {
      if (j != i) {
        totalCost += c[j].p + c[j].s;
        if (totalCost > m)
          break;
        numBuy++;
      }
    }
    ans = std::max(ans, numBuy);
  }
  std::cout << ans;

  return 0;
}