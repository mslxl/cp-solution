// See https://www.acwing.com/solution/content/24644/

#include <algorithm>
#include <cstdio>
#include <cstring>


using namespace std;
typedef long long ll;
const int N = 1005;

int n, m;
int w[N][N];
ll f[N][N][2];

ll Max(const ll a, const ll b, const ll c) {
  if (a > b)
    return a > c ? a : c;
  return b > c ? b : c;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf("%d", &w[i][j]);

  memset(f, 0xcf, sizeof f);
  f[1][0][0] = 0;
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++)
      f[i][j][0] =
          Max(f[i][j - 1][0], f[i][j - 1][1], f[i - 1][j][0]) + w[i][j];
    for (int i = n; i; i--)
      f[i][j][1] =
          Max(f[i][j - 1][0], f[i][j - 1][1], f[i + 1][j][1]) + w[i][j];
  }
  printf("%lld\n", f[n][m][0]);
  return 0;
}