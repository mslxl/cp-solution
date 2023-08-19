#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x, n, k = 1, opt, dp[100005];
bool isp[100005], vis[100005], has[100005];
vector<int> prime;
void seive() {
  for (int i = 2; i <= n; i++)
    if (!vis[i]) {
      isp[i] = 1;
      prime.push_back(i);
      for (ll j = (long long)i * i; j <= n; j += i)
        vis[j] = 1;
    }
}
int main() {
  scanf("%d%d", &opt, &n);
  if (opt == 2)
    scanf("%d", &k);
  prime.push_back(1);
  seive();
  if (!isp[k])
    prime.push_back(k);
  sort(prime.begin(), prime.end());
  has[k] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = isp[i];
    for (auto p : prime) {
      if (p >= i)
        break;
      int tmp = dp[p] + dp[i - p] + isp[i];
      if (tmp > dp[i])
        dp[i] = tmp, has[i] = ((i == k) | has[p] | has[i - p]);
      else if (tmp == dp[i])
        has[i] |= ((i == k) | has[p] | has[i - p]);
    }
  }
  printf("%d\n", dp[n]);
  if (opt == 2)
    printf("%d\n", has[n]);
  return 0;
}