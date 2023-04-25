#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
const int N = 3e5 + 17;
using ll = long long;

int n, root;
vector<int> g[N];
ll fact[N], dp[N], mx[N], d[N], deg[N], c[N];

ll qmi(ll a, ll b, ll p) {
  ll res = 1;
  a %= p;
  while (b) {
    if (b & 1) res = res * a % p;
    b >>= 1;
    a = a * a % p;
  }
  return res;
}

int lowbit(int x) { return x & (-x); }

void add(int x, int val) {
  for (int i = x; i <= n; i += lowbit(i)) c[i] += val;
}

ll query(int x) {
  ll res = 0;
  for (int i = x; i; i -= lowbit(i)) res += c[i];
  return res;
}

void dfs(int u, int fa) {
  mx[u] = query(n) - query(u);
  add(u, 1);
  dp[u] = 1;
  for (auto &x : g[u])
    if (x != fa) {
      deg[u]++;
      dfs(x, u);
      dp[u] = dp[u] * dp[x] % mod;
      d[u] += d[x];
    }
  d[u] += deg[u];
  dp[u] = dp[u] * fact[deg[u]] % mod;
  add(u, -1);
}

ll cal(ll x) { return x * (x - 1) % mod * qmi(2, mod - 2, mod) % mod; }

void solve() {
  scanf("%d%d", &n, &root);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  fact[0] = 1;
  for (ll i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;

  dfs(root, 0);
  ll tmp = cal(n);
  for (int i = 1; i <= n; i++) tmp -= d[i], tmp %= mod;
  // cout << tmp << '\n';
  ll res = tmp * qmi(2, mod - 2, mod) % mod;
  for (int i = 1; i <= n; i++) res += mx[i], res %= mod;
  res = res * dp[root] % mod;
  cout << (res + mod) % mod;
}

int main() {
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}