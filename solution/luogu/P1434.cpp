// SHOI2022 滑雪
#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = s; i < e; i++)

const int maxrc = 100 + 17;

std::array<std::array<int, maxrc>, maxrc> map;

int max_len = 0;
int lendp[maxrc][maxrc];

int R, C;

bool vis[maxrc][maxrc];

int dfs(int r, int c) {
  if (vis[r][c]) {
    return lendp[r][c];
  }
  vis[r][c] = true;
  if (r > 0) {
    if (map[r - 1][c] < map[r][c]) {
      lendp[r][c] = std::max(dfs(r - 1, c) + 1, lendp[r][c]);
    }
  }
  if (c > 0) {
    if (map[r][c - 1] < map[r][c]) {
      lendp[r][c] = std::max(dfs(r, c - 1) + 1, lendp[r][c]);
    }
  }
  if (map[r + 1][c] < map[r][c]) {
    lendp[r][c] = std::max(dfs(r + 1, c) + 1, lendp[r][c]);
  }
  if (map[r][c + 1] < map[r][c]) {
    lendp[r][c] = std::max(dfs(r, c + 1) + 1, lendp[r][c]);
  }
  return lendp[r][c];
}

int main() {
  std::memset(lendp, 0, sizeof(lendp));
  std::memset(vis, false, sizeof(vis));
  scanf("%d%d", &R, &C);

  rep(i, 0, R) {
    rep(j, 0, C) {
      scanf("%d", &map[i][j]);
      lendp[i][j] = 1;
    }
  }

  int ans = 0;
  rep(i, 0, R) {
    rep(j, 0, C) {
      int len = dfs(i, j);
      ans = std::max(len, ans);
      // std::cerr << len << ' ';
    }
    // std::cerr << std::endl;
  }
  printf("%d", ans);

  return 0;
}