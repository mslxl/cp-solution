#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5 + 100;
const int INF = 0x3f3f3f3f;
int dis[maxn], vis[maxn], flow[maxn], pre[maxn], id[maxn];
int a[maxn], l[maxn], r[maxn];
int n, m, s, t;
struct edge {
  int to, nxt, flow, w;
} d[maxn];
int head[maxn], cnt = 1;
void add(int u, int v, int flow, int w) {
  d[++cnt] = (edge){v, head[u], flow, w}, head[u] = cnt;
  d[++cnt] = (edge){u, head[v], 0, -w}, head[v] = cnt;
}
bool spfa(int s, int t, int mx) {
  for (int i = 0; i <= mx; i++) dis[i] = INF, vis[i] = 0;
  queue<int> q;
  q.push(s);
  dis[s] = 0, flow[s] = INF;
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; i; i = d[i].nxt) {
      int v = d[i].to;
      if (d[i].flow && dis[u] + d[i].w < dis[v]) {
        dis[v] = dis[u] + d[i].w, pre[v] = i;
        flow[v] = min(d[i].flow, flow[u]);
        if (!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return dis[t] != INF;
}
int Cost_Flow(int s, int t, int mx) {
  int mincost = 0;
  while (spfa(s, t, mx)) {
    mincost += dis[t] * flow[t];
    int x = t, i;
    while (x != s) {
      i = pre[x];
      d[i].flow -= flow[t], d[i ^ 1].flow += flow[t];
      x = d[i ^ 1].to;
    }
  }
  return mincost;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d%d", &l[i], &r[i]);
    s = 0, t = n + m + 1;
    for (int i = 1; i <= m; i++) {
      add(s, i, 1, 0);
      id[i] = cnt + 1;
      add(i, m + l[i], 1, 0);
      add(i, m + r[i], 1, 0);
    }
    for (int i = 1; i <= n; i++) {
      add(m + i, t, a[i], 0);
      add(m + i, t, INF, 1);
    }
    printf("%d\n", Cost_Flow(s, t, n + m + 1));
    for (int i = 1; i <= m; i++) printf("%d", d[id[i]].flow == 0 ? 1 : 0);
    printf("\n");
    cnt = 1;
    for (int i = 0; i <= t; i++) head[i] = 0;
  }
  return 0;
}