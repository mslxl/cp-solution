#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int maxn = 1e4 + 17;
int n;

struct {
  int to, next;
} edges[maxn];
int heads[maxn] = {0}, eid = 0;

void add_edge(int u, int v) {
  eid++;
  edges[eid].to = v;
  edges[eid].next = heads[u];
  heads[u] = eid;
}

int parent[maxn];
int depth[maxn];

int F[maxn][21];

void ST_create() {
  for (int i = 1; i <= n; i++) {
    std::memset(F[i], 0, sizeof(F[i]));
    F[i][0] = parent[i];
  }
  const int k = log2(n);
  for (int j = 1; j <= k; j++) {
    for (int i = 1; i <= n; i++) {
      F[i][j] = F[F[i][j - 1]][j - 1];
    }
  }
}

int LCA(int x, int y) {
  const int k = log2(n);
  if (depth[x] > depth[y]) {
    std::swap(x, y); // 保证 y 的深度大
  }
  for (int i = k; i >= 0; i--) {
    if (depth[F[y][i]] >= depth[x]) {
      y = F[y][i];
    }
  }
  if (x == y) {
    return x;
  }
  for (int i = k; i >= 0; i--) {
    if (F[x][i] != F[y][i]) {
      x = F[x][i];
      y = F[y][i];
    }
  }
  return F[x][0];
}

int find_root(int u) {
  while (parent[u] != 0) {
    u = parent[u];
  }
  return u;
}

bool vis[maxn] = {false};
void dfs(int u, int d = 1) {
  vis[u] = true;
  depth[u] = d;
  for (int i = heads[u]; i != 0; i = edges[i].next) {
    const int v = edges[i].to;
    if (!vis[v]) {
      dfs(v, d + 1);
    }
  }
}

void solve() {
  std::memset(heads, 0, sizeof(heads));
  std::memset(edges, 0, sizeof(edges));
  std::memset(vis,false,sizeof(vis));
  std::memset(parent,0,sizeof(parent));
  eid = 0;
  std::cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int child, par;
    std::cin >> par >> child;
    parent[child] = par;
    add_edge(par, child);
  }
  int root = find_root(n);
  dfs(root);
  ST_create();
  int x, y;
  std::cin >> x >> y;
  std::cout << LCA(x, y) << std::endl;
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}