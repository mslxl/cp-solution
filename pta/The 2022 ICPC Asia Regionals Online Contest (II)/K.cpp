#include <bits/stdc++.h>
#define int long long
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int modd = 998244353;
const int maxn = 200 + 17;
long long s[maxn][maxn], radius[16];

int qpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % modd;
    a = 1ll * a * a % modd;
    b >>= 1;
  }
  return res;
}

#undef int
int main() {
#define int long long
  int n;
  std::cin >> n;
  while (n--) {
    int op, x, y;
    std::cin >> op >> x >> y;
    x += 102, y += 102;
    if (op == 1) s[x][y] = std::max(s[x][y], 2ll);
    if (op == 2) s[x][y] = std::max(s[x][y], 1ll);
  }
  int a = 0, b = 0;
  for (int x = 2; x <= 202; x++) {
    for (int y = 2; y <= 202; y++) {
      if (s[x][y] == 1) {
        memset(radius, 0, sizeof radius);
        if (s[x - 1][y - 1]) radius[0] = radius[1] = radius[2] = 1;

        if (s[x - 1][y] == 1) radius[1] = radius[2] = radius[3] = radius[4] = 1;
        if (s[x - 1][y] == 2)
          radius[0] = radius[1] = radius[2] = radius[3] = radius[4] =
              radius[5] = 1;

        if (s[x - 1][y + 1]) radius[3] = radius[4] = radius[5] = 1;

        if (s[x][y + 1] == 1) radius[4] = radius[5] = radius[6] = radius[7] = 1;
        if (s[x][y + 1] == 2)
          radius[3] = radius[4] = radius[5] = radius[6] = radius[7] =
              radius[8] = 1;

        if (s[x + 1][y + 1]) radius[6] = radius[7] = radius[8] = 1;

        if (s[x + 1][y] == 1)
          radius[7] = radius[8] = radius[9] = radius[10] = 1;
        if (s[x + 1][y] == 2)
          radius[6] = radius[7] = radius[8] = radius[9] = radius[10] =
              radius[11] = 1;

        if (s[x + 1][y - 1]) radius[9] = radius[10] = radius[11] = 1;

        if (s[x][y - 1] == 1)
          radius[10] = radius[11] = radius[0] = radius[1] = 1;
        if (s[x][y - 1] == 2)
          radius[9] = radius[10] = radius[11] = radius[0] = radius[1] =
              radius[2] = 1;

        for (int i = 0; i < 12; i++)
          if (radius[i] == 0) b++;
      }
      if (s[x][y] == 2) {
        memset(radius, 0, sizeof radius);
        if (s[x - 1][y - 1]) radius[0] = radius[1] = INF;

        if (s[x - 1][y] == 1) radius[1] = radius[2] = INF;
        if (s[x - 1][y] == 2)
          radius[1] = radius[2] = INF, radius[0]++, radius[3]++;

        if (s[x - 1][y + 1]) radius[2] = radius[3] = INF;

        if (s[x][y + 1] == 1) radius[3] = radius[4] = INF;
        if (s[x][y + 1] == 2)
          radius[3] = radius[4] = INF, radius[2]++, radius[5]++;

        if (s[x + 1][y + 1]) radius[4] = radius[5] = INF;

        if (s[x + 1][y] == 1) radius[5] = radius[6] = INF;
        if (s[x + 1][y] == 2)
          radius[5] = radius[6] = INF, radius[4]++, radius[7]++;

        if (s[x + 1][y - 1]) radius[6] = radius[7] = INF;

        if (s[x][y - 1] == 1) radius[7] = radius[0] = INF;
        if (s[x][y - 1] == 2)
          radius[7] = radius[0] = INF, radius[1]++, radius[6]++;

        if (s[x - 2][y] == 2) radius[1] = radius[2] = INF;
        if (s[x - 2][y - 1] == 2) radius[1] = INF;
        if (s[x - 2][y + 1] == 2) radius[2] = INF;

        if (s[x][y + 2] == 2) radius[3] = radius[4] = INF;
        if (s[x - 1][y + 2] == 2) radius[3] = INF;
        if (s[x + 1][y + 2] == 2) radius[4] = INF;

        if (s[x + 2][y] == 2) radius[5] = radius[6] = INF;
        if (s[x + 2][y + 1] == 2) radius[5] = INF;
        if (s[x + 2][y - 1] == 2) radius[6] = INF;

        if (s[x][y - 2] == 2) radius[7] = radius[0] = INF;
        if (s[x + 1][y - 2] == 2) radius[7] = INF;
        if (s[x - 1][y - 2] == 2) radius[0] = INF;

        for (int i = 0; i < 8; i++) {
          if (radius[i] == 1) a += 1;
          if (radius[i] == 0) a += 2;
        }
      }
    }
  }
  a = a * qpow(2, modd - 2) % modd;
  b = b * qpow(6, modd - 2) % modd;
  std::cout << a << " " << b;
}