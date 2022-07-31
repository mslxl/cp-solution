#include <bits/stdc++.h>

const int maxn = 5e5 + 17;
const int maxseq = maxn * 2 + 17;
struct Node {
  int to;
  int next;
} edges[maxseq];

int heads[maxseq] = {0}, eid = 0;

void add_edge(int u, int v) {
  eid++;
  edges[eid].to = v;
  edges[eid].next = heads[u];
  heads[u] = eid;
}

int pos[maxseq] = {-1};
int seq[maxseq] = {-1};
int dep[maxseq] = {-1};
bool vis[maxseq] = {false};

int cur_pos = 0;
void dfs(int u, int depth) {
  vis[u] = true;
  cur_pos++;
  pos[u] = cur_pos;
  seq[cur_pos] = u;
  dep[cur_pos] = depth;

  for (int i = heads[u]; i != 0; i = edges[i].next) {
    const int v = edges[i].to;
    if (!vis[v]) {
      dfs(v, depth + 1);
      cur_pos++;
      seq[cur_pos] = u;
      dep[cur_pos] = depth;
    }
  }
}

int F[maxseq][42] = {0};

void ST_create() {
  for (int i = 1; i <= cur_pos; i++) {
    F[i][0] = i; // !important 记录的是下标，不是最小深度
  }
  int k = std::log2(cur_pos);
  for (int j = 1; j <= k; j++) {
    for (int i = 1; i <= cur_pos - (1 << j) + 1; i++) { // cur_pos - 2^j + 1
      if (dep[F[i][j - 1]] <
          dep[F[i + (1 << (j - 1))][j - 1]]) { //! important
                                               //! 比较的是最小深度
        F[i][j] = F[i][j - 1];
      } else {
        F[i][j] = F[i + (1 << (j - 1))][j - 1];
      }
    }
  }
}

int ST_query(int l, int r) {
  int k = std::log2(r - l + 1);
  if (dep[F[l][k]] < dep[F[r - (1 << k) + 1][k]]) {
    return F[l][k];
  } else {
    return F[r - (1 << k) + 1][k];
  }
}

int LCA(int x, int y) {
  int l = pos[x], r = pos[y];
  if (l > r)
    std::swap(l, r);
  int idx = ST_query(l, r);
  std::cerr << std::endl;
  return seq[idx];
}

int N, M, S;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M >> S;
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    std::cin >> v >> u;
    add_edge(u, v);
    add_edge(v, u);
  }
  dfs(S, 1);

  ST_create();
  for (int i = 0; i < M; i++) {
    int x, y;
    std::cin >> x >> y;
    std::cout << LCA(x, y) << std::endl;
  }

  return 0;
}