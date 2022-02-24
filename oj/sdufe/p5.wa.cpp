#include <bits/stdc++.h>

inline int rd() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}

typedef long long ll;

const int modd = 998244353;
int n, m;
int *g = nullptr, *rank = nullptr;
ll ans = 0;

inline void append_bin(bool f) { ans = (ans << 1) | f; }

inline int find_root(int u) {
  while (g[u] != 0) {
    u = g[u];
  }
  return u;
}

inline bool is_joint(int u, int v) { return find_root(u) == find_root(v); }

inline void union_node(int u, int v) {
  int root_u = find_root(u);
  int root_v = find_root(v);
  if (root_u != root_v) {
    if (rank[root_u] > rank[root_v]) {
      g[root_v] = root_u;
    } else if (rank[root_u] < rank[root_v]) {
      g[root_u] = root_v;
    } else {
      g[root_u] = root_v;
      rank[root_v]++;
    }
  }
}

int main() {
  n = rd();
  m = rd();
  g = new int[n + 10];
  rank = new int[n + 10];
  std::memset(g, 0, sizeof(int) * (n + 10));
  std::memset(rank, 0, sizeof(int) * (n + 10));
  int op, u, v;
  for (int i = 0; i < m; i++) {

    op = rd(), u = rd(), v = rd();

    if (op) {
      // query
      append_bin(is_joint(u, v));
    } else {
      // link
      union_node(u, v);
    }
  }
  printf("%lld", ans % modd);

  return 0;
}
