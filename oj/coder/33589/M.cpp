#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = s; i < e; i++)
const int maxn = 500 + 17;
int parent[maxn];
int rank[maxn];

int find(int x) {
  while (parent[x] != 0) {
    x = parent[x];
  }
  return x;
}

bool is_joint(int x, int y) {
  return find(x) == find(y);
}

void joint(int x, int y) {
  int root_x = find(x);
  int root_y = find(y);
  if (root_x == root_y)
    return;
  parent[root_x] = root_y;
}

char G[maxn][maxn];
unsigned int color[maxn][maxn];
int color_idx = 1;
char A[maxn][maxn];
int n, m;

bool dye(int x, int y, int c) {
  if (x < 0 || y < 0 || x >= n || y >= m) {
    return;
  }
  if (G[y][x] == '0') {
    return false;
  }
  color[y][x] = c;
  dye(x - 1, y, c);
  dye(x + 1, y, c);
  dye(x, y - 1, c);
  dye(x, y + 1, c);
  return true;
}

int is_all_joint() {
  rep(i, 1, color_idx) {
    if (!is_joint(1, i))
      return i;
  }
  return 0;
}

int main() {
#ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif

  std::cin >> n >> m;

  rep(i, 0, n) {
    rep(j, 0, m) {
      std::cin >> G[i][j];
      A[i][j] = G[i][j];
    }
  }

  rep(i, 0, n) {
    rep(j, 0, m) {
      if (dye(i, j, color_idx))
        color_idx++;
    }
  }

  int unjoint;

  while ((is_all_joint())){

  }

  return 0;
}