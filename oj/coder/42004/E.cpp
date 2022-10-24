//小虫
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e6 + 10;
int T = 1;
int n;
ll k;
int a[N];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
void solve() {
  bool ok = false;
  int max1 = 2e6 + 5, max2 = 2e6 + 5;
  n = read();
  cin >> k;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    if (a[i] > a[max1])
      max1 = i;
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    x = read();
    y = read();
    if (x == max1) {
      if (a[y] > a[max2])
        max2 = y, ok = true;
      if (a[y] == a[max2] && y < max2)
        max2 = y, ok = true;
    }
    if (y == max1) {
      if (a[x] > a[max2])
        max2 = x, ok = true;
      if (a[x] == a[max2] && x < max2)
        max2 = x, ok = true;
    }
  }
  if (!ok) {
    printf("%d\n", max1);
    return;
  }
  int h = a[max1] - a[max2];
  if (h > k)
    printf("%d\n", max1);
  else if (h == k)
    printf("%d\n", min(max1, max2));
  else if ((k - h) % 2)
    printf("%d\n", max(max1, max2));
  else
    printf("%d\n", min(max1, max2));
}
int main() {
  cin >> T;
  while (T--)
    solve();
  return 0;
}