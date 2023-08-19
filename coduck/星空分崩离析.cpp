#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, q;
vector<int> g[maxn];
int dep[maxn], down[maxn], fa[maxn];
int ask, num;
int ans[maxn];
void init(int x, int f) {
  dep[x] = dep[f] + 1;
  fa[x] = f;
  int maxx = -1;
  for (int i = 0; i < g[x].size(); i++) {
    int y = g[x][i];
    if (y == f) {
      continue;
    }
    init(y, x);
    maxx = max(maxx, down[y]);
  }
  down[x] = maxx + 1;
}
void get(int x) {
  if (x == 1 && g[x].size() <= 0) {
    return;
  }
  if (x != 1 && g[x].size() <= 1) {
    return;
  }
  int res = 0;
  priority_queue<int> q;
  q.push(0);
  for (int i = 0; i < g[x].size(); i++) {
    int y = g[x][i];
    if (y == fa[x]) {
      continue;
    }
    q.push(down[y] + 1);
  }
  for (int i = 1; i <= 2; i++) {
    int tmp = q.top();
    q.pop();
    res += tmp;
    if (i == 2) {
      ans[dep[x] + tmp] = max(ans[dep[x] + tmp], res);
    }
  }
}
void dfs(int x) {
  get(x);
  for (int i = 0; i < g[x].size(); i++) {
    int y = g[x][i];
    if (y == fa[x]) {
      continue;
    }
    dfs(y);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> ask;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dep[1] = -1;
  init(1, 1);
  dfs(1);
  for (int i = n - 1; i >= 1; i--) {
    ans[i] = max(ans[i], ans[i + 1]);
  }
  for (int i = 1; i <= ask; i++) {
    cin >> num;
    if (ans[num + 1] == 0) {
      cout << -1 << '\n';
    } else {
      cout << ans[num + 1] << '\n';
    }
  }
  return 0;
}