#include <bits/stdc++.h>

#define rd(x) x = read()

#define N 20005

using namespace std;

int n, m;

struct E {
  int to, nxt, w;
} e[N];
int tot;
int ans, pos;
int head[N], dis[N];

void addEdge(int u, int v, int w) {
  e[++tot].nxt = head[u], e[tot].to = v, e[tot].w = w, head[u] = tot;
}

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10)
    write(x / 10);
  putchar(x % 10 + '0');
}

void dfs(int u, int fa) {
  if (ans < dis[u])
    ans = dis[u], pos = u;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa)
      continue;
    dis[v] = dis[u] + e[i].w;
    dfs(v, u);
  }
}

int main() {
  rd(n);
  for (int i = 1; i <= n - 1; i++) {
    int u, v, w;
    rd(u), rd(v), rd(w);
    addEdge(u, v, w);
    addEdge(v, u, w);
  }
  dis[1] = 0, dfs(1, 0);
  ans = 0, dis[pos] = 0, dfs(pos, 0);
  cout << ans << endl;

  return 0;
}