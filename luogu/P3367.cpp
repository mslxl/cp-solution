#include <bits/stdc++.h>

int *parent = nullptr, *rank = nullptr;
int N, M;

int find_root(int u) {
  while (parent[u] != 0) {
    u = parent[u];
  }
  return u;
}

void union_node(int u, int v) {
  int root_u = find_root(u);
  int root_v = find_root(v);
  if (root_v == root_u)
    return;
  // 压缩路径，总是把高度小的树拼接到高度大的树上
  // 另外一个压缩方式是在 find_root 时采用记忆化搜索
  if (rank[root_u] > rank[root_v]) {
    parent[root_v] = root_u;
  } else if (rank[root_u] < rank[root_v]) {
    parent[root_u] = root_v;
  } else {
    parent[root_u] = root_v;
    rank[root_v]++;
  }
}

bool is_joint(int u, int v) { return find_root(u) == find_root(v); }

int main() {
  scanf("%d%d", &N, &M);
  parent = new int[N + 1];
  rank = new int[N + 1];
  std::memset(parent, 0, sizeof(int) * (N + 1));
  std::memset(rank, 0, sizeof(int) * (N + 1));

  int op, u, v;
  while (M--) {
    scanf("%d%d%d", &op, &u, &v);
    if (op == 1) {
      union_node(u, v);
    } else {
      printf("%c\n", is_joint(u, v) ? 'Y' : 'N');
    }
  }
}
