#include <bits/stdc++.h>
#include <memory>
#include <queue>

using ll = long long;
using ul = unsigned long long;
using ld = long double;
const int maxn = 100 + 17;
const int maxm = (500 + 17) * 2 + 1;

struct edge {
  int to;
  int w, v;
  int next;
} e[maxm];

int head[maxn], eid = 0;
void add_edge(int u, int v, int w, int vv) {
  eid++;
  e[eid].to = v;
  e[eid].w = w;
  e[eid].v = vv;
  e[eid].next = head[u];
  head[u] = eid;
}

int n, m, c;

int targetMax = -1;

void dfs(int curPt, std::set<int> vis, int remainCost, int max) {
  if(remainCost < 0) return;
  if (curPt == n) {
    targetMax = std::max(targetMax, max);
    return;
  }
  for (int i = head[curPt]; i; i = e[i].next) {
    if (vis.count(e[i].to))
      continue;
    std::set<int> nvis = vis;
    nvis.insert(e[i].to);
    dfs(e[i].to, nvis, remainCost - e[i].v, std::min(max, e[i].w));
  }
}

int main() {
  std::cin >> n >> m >> c;
  for (int i = 0; i < m; i++) {
    int x, y, w, v;
    std::cin >> x >> y >> w >> v;
    add_edge(x, y, w, v);
    add_edge(y, x, w, v);
  }
  dfs(1, {1}, c, 0x3f3f3f);
  std::cout << targetMax;

  return 0;
}