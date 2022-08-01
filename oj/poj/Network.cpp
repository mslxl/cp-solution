#include <cstring>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const int maxn = 100 + 17;
const int max_edge = maxn * maxn + 17;
struct {
  int to;
  int next;
} e[max_edge * 2 + 1];
int heads[maxn], eid = 0;

int dfn[maxn], low[maxn], num = 0, root;
std::set<int> ans;

void reinit() {
  eid = 0;
  num = 0;
  std::memset(e, 0, sizeof(e));
  std::memset(heads, 0, sizeof(heads));
  std::memset(dfn, 0, sizeof(dfn));
  std::memset(low, 0, sizeof(low));
  ans.clear();
}

void add_edge(int u, int v) {
  eid++;
  e[eid].to = v;
  e[eid].next = heads[u];
  heads[u] = eid;
}

void tarjan(int u, int father) {
  dfn[u] = low[u] = ++num;
  int cnt = 0;
  for (int i = heads[u]; i; i = e[i].next) {
    const int v = e[i].to;
    if (v == father)
      continue;
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = std::min(low[u], low[v]);

      if (low[v] >= dfn[u]) {
        cnt++;
        if (u != root || cnt > 1) {
          ans.insert(u);
        }
      }
    } else {
      low[u] = std::min(low[u], dfn[v]);
    }
  }
}

void solve(const int N) {
  reinit();
  std::string line;
  std::stringstream buf;
  while (true) {
    std::getline(std::cin, line);
    int u;
    buf.clear();
    buf << line;
    buf >> u;
    if (u == 0) {
      break;
    }
    int v;
    while (buf >> v) {
      add_edge(u, v);
      add_edge(v, u);
    }
  }
  root = 1;
  tarjan(1, 0);
  std::cout << ans.size() << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int T;
  while (true) {
    std::cin >> T;
    if (T == 0) {
      break;
    }
    std::cin.get();
    solve(T);
  }
  return 0;
}