#include <cstring>
#include <iostream>
#include <iterator>
#include <stack>

const int maxn = 5000 + 17;
const int maxe = maxn * 300 + 17;

struct _Edge {
  int next;
  int to;

} edges[maxe];
int heads[maxn], eid;

int id;

void add_edge(int u, int v) {
  eid++;
  edges[eid].to = v;
  edges[eid].next = heads[u];
  heads[u] = eid;
}

int n, m;

int dfn[maxn], low[maxn], ttl = 0;
int outdrgree[maxn], belong[maxn];

void clear() {
#define cls(x) std::memset(x, 0, sizeof(x))
  id = 1;
  ttl = eid = 0;
  cls(edges);
  cls(heads);
  cls(dfn);
  cls(low);
  cls(outdrgree);
  cls(belong);
#undef cls
}
std::stack<int> s;

void tarjan(int u) {
  ttl++;
  dfn[u] = low[u] = ttl;
  s.push(u);
  for (int i = heads[u]; i; i = edges[i].next) {
    const int v = edges[i].to;
    if (!dfn[v]) {
      tarjan(v);
      low[u] = std::min(low[u], low[v]);
    } else {
      low[u] = std::min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) {
    int v;
    do {
      v = s.top();
      s.pop();
      belong[v] = id;
    } while (v != u);
    id++;
  }
}

void solve() {
  clear();
  for (int i = 0; i < m; i++) {
    int v, w;
    std::cin >> v >> w;
    add_edge(v, w);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) {
      tarjan(i);
    }
  }

  for (int u = 1; u <= n; u++) {
    for (int i = heads[u]; i; i = edges[i].next) {
      const int v = edges[i].to;
      if (belong[u] != belong[v]) {
        outdrgree[belong[u]]++;
      }
    }
  }
  

  bool fst = true;
  for (int i = 1; i <= n; i++) {
    if (!outdrgree[belong[i]]) {
      if (!fst)
        std::cout << " ";
      else {
        fst = false;
      };
      std::cout << i;
    }
  }
  std::cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  while (true) {
    std::cin >> n;
    if (n == 0)
      break;
    std::cin >> m;
    solve();
  }

  return 0;
}