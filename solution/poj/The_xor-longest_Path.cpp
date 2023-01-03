#include <cstring>
#include <iostream>


const int maxn = 1e6 + 5;
struct Edge {
  int to, next, w;
} e[maxn * 2 + 1];
int head[maxn], eid = 0;
void add_edge(int u, int v, int w) {
  eid++;
  e[eid].to = v;
  e[eid].w = w;
  e[eid].next = head[u];
  head[u] = eid;
}

const int max_depth = maxn;
const int max_bit_len = 30;
int trie[max_depth][2];
int total_depth = 0;
void insert(int num) {

  int depth = 0;
  for (int i = max_bit_len; i >= 0; i--) {
    bool b = num & (1 << i);

    if (!trie[depth][b]) {
      total_depth++;
      trie[depth][b] = total_depth;
    }
    depth = trie[depth][b];
  }
}

int find(int num) {
  int depth = 0, result = 0;
  for (int i = max_bit_len; i >= 0; i--) {
    bool k = num & (1 << i);

    
    if (trie[depth][k ^ 1]) {
      result += 1 << i;
      depth = trie[depth][k ^ 1];
    } else {
      depth = trie[depth][k];
    }
  }
  return result;
}

int n;
int dx[maxn];
void dfs(int u, int fa) {
  for (int i = head[u]; i; i = e[i].next) {
    const int v = e[i].to, w = e[i].w;
    if (v == fa)
      continue;
    dx[v] = dx[u] ^ w;
    dfs(v, u);
  }
}

void solve() {
  using std::cin;
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    //std::cerr << u << v << w << "\n";
    add_edge(u, v, w);
    add_edge(v, u, w);
  }
  dfs(0, 0);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    insert(dx[i]);
    ans = std::max(ans, find(dx[i]));
  }
  std::cout << ans << std::endl;
}
void init() {
  memset(e, 0, sizeof(e));
  memset(head, 0, sizeof(head));
  eid = 0;
  memset(dx, 0, sizeof(dx));
  memset(trie, 0, sizeof(trie));
  total_depth = 0;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
    init();
    solve();


  return 0;
}