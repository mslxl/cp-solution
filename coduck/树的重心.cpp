#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<double, ll> pdl;
#define debug(x) cerr << "# " << x << endl
const ll N = 200005;
const ll base = 137;
const ll mod = 2147483647;
const int INF = 1 << 30;

ll head[N];
ll son[N];
ll cnt, n;
ll ans, sz;
bool vis[N];
struct Edge {
  ll to;
  ll nex;
};
Edge edge[2 * N];
inline void init() {
  cnt = 0;
  sz = INF;
  memset(vis, 0, sizeof(vis));
  memset(head, -1, sizeof(head));
}
inline void add(ll u, ll v) {
  edge[cnt].to = v;
  edge[cnt].nex = head[u];
  head[u] = cnt++;
}
inline void dfs(ll cur) {
  vis[cur] = 1;
  son[cur] = 1;
  ll tmp = 0;
  for (ll i = head[cur]; ~i; i = edge[i].nex) {
    ll v = edge[i].to;
    if (!vis[v]) {
      dfs(v);
      son[cur] += son[v];
      tmp = max(tmp, son[v]);
    }
  }
  tmp = max(tmp, n - son[cur]);
  if (tmp < sz || (tmp == sz && cur < ans)) {
    ans = cur;
    sz = tmp;
  }
}
int main() {
  ll T;
  T = 1;
  while (T--) {
    init();
    scanf("%lld", &n);
    ll s;
    cin >> s;
    for (int i = 1; i <= n - 1; ++i) {
      ll u, v;
      scanf("%lld %lld", &u, &v);
      add(u, v);
      add(v, u);
    }
    dfs(s);
    printf("%lld %lld\n", ans, sz);
  }
  return 0;
}
