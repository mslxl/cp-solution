#include <algorithm>
#include <iostream>
#include <vector>

#define rp(i, s, e) for (int i = s; i < e; i++)
const auto cmp = std::greater<int>();

void solve() {
  int A, B, n;
  std::cin >> A >> B >> n;
  std::vector<int> va(A), vb(B);

  rp(i, 0, A) std::cin >> va[i];
  rp(i, 0, B) std::cin >> vb[i];
  std::sort(va.begin(), va.end(), cmp);
  std::sort(vb.begin(), vb.end(), cmp);
  rp(i, 1, A) va[i] = va[i] + va[i - 1];
  rp(i, 1, B) vb[i] = vb[i] + vb[i - 1];

  int max_noise = std::min(n / 2, (int)vb.size());

  if (max_noise + va.size() < n) {
    std::cout << -1 << std::endl;
    return;
  }

  int ans = -1;
  rp(ia, 0, A + 1) {
    int ib = n - ia;
    if (ib > max_noise || ib < 0)
      continue;
    ans = std::max(ans, va[ia - 1] + vb[ib - 1]);
  }

  std::cout << ans << std::endl;
}

int main() {
  int T;
  std::cin >> T;
  while (T-- > 0) {
    solve();
  }
}
