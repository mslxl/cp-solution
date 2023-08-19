#include <algorithm>
#include <bits/stdc++.h>

double f[10010];

int n, m;
int a[10010];
double b[10010];
int main() {
  while (std::cin >> n >> m && n != 0 && m != 0) {
    for (int i = 1; i <= m; i++) {
      std::cin >> a[i] >> b[i];
      b[i] = 1 - b[i];
    }
    for (int i = 0; i < 10010; i++) {
      f[i] = 1;
    }

    for (int i = 1; i <= m; i++) {
      for (int j = n; j >= a[i]; j--) {
        f[j] = std::min(f[j], f[j - a[i]] * b[i]);
      }
    }
    double ans = 100 - 100 * f[n];
    printf("%.1lf%%\n", ans);
  }
}