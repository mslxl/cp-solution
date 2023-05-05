#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>

int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}

const int maxn = 1e5 + 11;
int a[maxn], n, m;

int main() {
  int t = read();
  while (t--) {
    n = read();
    m = read();
    int num_zero = 0;
    for (int i = 1; i <= n; i++) {
      a[i] = read();
      if (a[i] == 0) {
        num_zero++;
      }
    }
    int ans = 0;
    if (num_zero > m) {
      std::cout << "Impossible\n";
      continue;
    }
    if (n == m) {
      std::cout << "Richman\n";  // r
      continue;
    }
    int point = 1;
    int num = 1;
    while (num <= m) {
      if (a[point] != 0) {
        num++;
        ans += a[point];
      }
      point++;
    }
    int minn = INT_MAX;
    for (int i = point; i <= n; i++) {
      if (a[i] != 0) {
        minn = std::min(minn, a[i]);
      }
    }
    ans += minn - 1;
    std::cout << ans << "\n";
  }
  return 0;
}
