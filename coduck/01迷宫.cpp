#include <cstdio>
#include <cstring>
int n, m, ans[100002], x, y, f[1002][1002];
char s[1002][1002];
void dfs(int r, int c, int z, int lll) {
  if (r < 0 || r >= n || c < 0 || c >= n || f[r][c] != -1 || s[r][c] - '0' != z)
    return;
  f[r][c] = lll;
  ans[lll]++;
  dfs(r - 1, c, !z, lll);
  dfs(r + 1, c, !z, lll);
  dfs(r, c - 1, !z, lll);
  dfs(r, c + 1, !z, lll);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%s", s[i]);
  memset(f, -1, sizeof(f));
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    if (f[x][y] == -1)
      dfs(x, y, s[x][y] - '0', i);
    else
      ans[i] = ans[f[x][y]];
  }
  for (int i = 0; i < m; i++)
    printf("%d\n", ans[i]);
  return 0;
}