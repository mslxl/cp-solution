#include <bits/stdc++.h>

const int MODD = 1e9 + 7;
const int MAXN = 12;
using ll = long long;

template <typename A, typename BaseT>
typename std::enable_if<std::is_integral<BaseT>::value, A>::type
qpow(A a, BaseT n, BaseT modd) {
  decltype(a) ans = 1;
  while (n) {
    if (n & 1)
      ans = (ans * a) % modd;
    n >>= 1;
    a = (a * a) % modd;
  }
  return ans % modd;
}

int a[MAXN][MAXN];
int m, n;
ll gcnt;

void dfs(int xx, int yy) {
  for (int color = 0; color < 3; color++) {
    int x2 = xx;
    int y2 = yy;
    a[y2][x2] = color;
    bool flag = true;
    for (int y1 = 0; y1 < y2 && flag; y1++) {
      for (int x1 = 0; x1 < x2 && flag; x1++) {
        if ((a[y1][x1] == a[y2][x1] && a[y1][x2] == a[y2][x2]) ||
            (a[y1][x1] == a[y1][x2] && a[y2][x1] == a[y2][x2])) {
          flag = false;
          gcnt += qpow(3LL, (n - 1 - y2) * m + (m - 1) - x2, MODD);
          gcnt %= MODD;
        }
      }
    }
    if (flag) {
      x2++;
      if (x2 >= m) {
        x2 = 0;
        y2++;
        if (y2 >= n) {
          continue;
        }
      }
      dfs(x2, y2);
    }
  }
  a[yy][xx] = -1;
}

int solve() {
  gcnt = 0;
  dfs(0, 0);
  return gcnt;
}

int main() {
  std::ofstream os("H.txt");

  for (n = 1; n <= 9; n++) {
    os << "{";
    for (m = 1; m <= 9; m++) {
      std::cout << n << "x" << m << "\n";
      if (std::min(n, m) == 1) {
        os << 0 << ",";
        continue;
      } else {
        std::memset(a, 0, sizeof(a));
        os << solve();
        if (m != 9) {
          os << ",";
        }
      }
    }
    os << "}";
    if (n != 9) {
      os << ",\n";
    }
  }
}
