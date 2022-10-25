
// 邮递员送信
#include <bits/stdc++.h>
#include <cstdint>
#include <queue>
#include <utility>

const int maxn = 1e3 + 17;
const int maxm = 1e5 + 17;

struct redge {
  int to;
  int next;
  int w;
} re[maxm];

struct edge {
  int to;
  int next;
  int w;
} e[maxm];
int eid, head[maxn];
int reid, rhead[maxn];

void add_redge(int u, int v, int w) {
  reid++;
  re[reid].to = v;
  re[reid].w = w;
  re[reid].next = rhead[u];
  rhead[u] = reid;
}
void add_edge(int u, int v, int w) {
  eid++;
  e[eid].to = v;
  e[eid].w = w;
  e[eid].next = head[u];
  head[u] = eid;
}

int n, m;

std::vector<int> dis;
std::vector<int> rdis;
std::vector<bool> vis;

void dj() {
  using ds = std::pair<int, int>;
  std::priority_queue<ds, std::vector<ds>, std::greater<ds>> seq;
  seq.push(std::make_pair(0, 1));
  while (!seq.empty()) {
    ds p = seq.top();
    seq.pop();
    const int u = p.second, w = p.first;
    if (vis[u])
      continue;
    vis[u] = true;

    for (int i = head[u]; i; i = e[i].next) {
      const int v = e[i].to;
      if (vis[v])
        continue;
      const int nw = e[i].w + w;
      dis[v] = std::min(nw, dis[v]);
      seq.push(std::make_pair(nw, v));
    }
  }
}

void rdj() {
  using ds = std::pair<int, int>;
  std::priority_queue<ds, std::vector<ds>, std::greater<ds>> seq;
  seq.push(std::make_pair(0, 1));
  while (!seq.empty()) {
    ds p = seq.top();
    seq.pop();
    const int u = p.second, w = p.first;
    if (vis[u])
      continue;
    vis[u] = true;

    for (int i = rhead[u]; i; i = re[i].next) {
      const int v = re[i].to;
      if (vis[v])
        continue;
      const int nw = re[i].w + w;
      rdis[v] = std::min(nw, rdis[v]);
      seq.push(std::make_pair(nw, v));
    }
  }
}

int main() {
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    add_edge(u, v, w);
    add_redge(v, u, w);
  }
  dis.resize(n + 1);
  rdis.resize(n + 1);

  std::fill(dis.begin(), dis.end(), INT32_MAX);
  std::fill(rdis.begin(), rdis.end(), INT32_MAX);
  dis[1] = rdis[1] = 0;
  vis.resize(n + 1);
  dj();
  std::fill(vis.begin(), vis.end(), false);
  rdj();
  unsigned long long ans = 0;
  for (int i = 2; i <= n; i++) {
    // std::cerr << 1 << "->" << i << ": " << dis[i] << std::endl;
    // std::cerr << i << "->" << 1 << ": " << rdis[i] << std::endl;
    ans += dis[i] + rdis[i];
  }
  std::cout << ans;
  return 0;
}