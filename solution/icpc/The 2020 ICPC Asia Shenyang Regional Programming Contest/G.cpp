#include <algorithm>
#include <iostream>
#define ull unsigned long long

const int maxn = 1011;
ull a[maxn];
ull cmp(ull s1, ull s2) { return s1 > s2; }
int main() {
  ull n, k;
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a + 1, a + 1 + n, cmp);
  ull ans = 0;
  for (int i = 1; i <= k; i++) {
    ans += a[i];
  }
  std::cout << ans;
  return 0;
}
