#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
int n, x, y;
int a[100010], b[100010];
long long ans;
int main() {
  std::cin >> n >> x >> y;
  for (int i = 1; i <= n; i++)
    std::cin >> a[i] >> b[i];
  std::sort(a + 1, a + 1 + n);
  std::sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) {
    if (a[i] < b[i])
      ans += (b[i] - a[i]) * x;
    else
      ans += (a[i] - b[i]) * y;
  }
  std::cout << ans;
  return 0;
}