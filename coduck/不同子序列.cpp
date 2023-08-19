#include <bits/stdc++.h>
using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 17;
ll a[maxn];
ll dp[maxn];
ll vis[maxn];
ll pos[maxn];

int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    vis[i] = pos[a[i]];
    pos[a[i]] = i;
  }
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      dp[i] = dp[i - 1] * 2 % mod + 1;
      dp[i] %= mod;
    } else {
      dp[i] = ((dp[i - 1] * 2 + mod) - dp[vis[i] - 1] % mod) % mod;
      dp[i] %= mod;
    }
    if (dp[i] == 0)
      dp[i] = (ll)1;
  }
  std::cout << dp[n] % mod;
}