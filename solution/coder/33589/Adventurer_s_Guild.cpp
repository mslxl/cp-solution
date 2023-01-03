#include <bits/stdc++.h>
using ll = long long;

ll dp[305][305];

struct node {
  int hp, stamina, w;
} a[1005];

int main() {
  int n, H, S;
  std::cin >> n >> H >> S;
  for (int i = 1; i <= n; ++i)
    std::cin >> a[i].hp >> a[i].stamina >> a[i].w;
  for (int i = 1; i <= n; i++) {
    for (int j = H; j >= 0; j--) {
      for (int k = S; k >= 0; k--) {
        if (k >= a[i].stamina && j > a[i].hp) {
          dp[j][k] = std::max(dp[j][k], dp[j - a[i].hp][k - a[i].stamina] + a[i].w);
        } else if (j > a[i].hp && j + k > a[i].stamina + a[i].hp) {
          int res = a[i].stamina - k;
          dp[j][k] = std::max(dp[j][k], dp[j - a[i].hp - res][0] + a[i].w);
        }
      }
    }
  }
  std::cout << dp[H][S] << std::endl;
  return 0;
}