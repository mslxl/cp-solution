#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <stdlib.h>
#include <queue>
 
using ll = long long;
const int N = 1000 + 17;
const int M = 300 + 17;
ll dp[M][M];
ll n, h, s;
struct Node
{
  ll h, s, w;
} a[N];
int main()
{
  std::cin >> n >> h >> s;
  for (int i = 1; i <= n; i++)
    std::cin >> a[i].h >> a[i].s >> a[i].w;
  for (int i = 1; i <= n; i++)
  {
    for (int j = h; j >= 1; j--)
    {
      for (int k = s; k >= 0; k--)
      {
        if (j > a[i].h && j + k > a[i].s + a[i].h)
        {
          if (k >= a[i].s)
            dp[j][k] = std::max(dp[j][k], dp[j - a[i].h][k - a[i].s] + a[i].w);
          else
            dp[j][k] = std::max(dp[j][k], dp[j - a[i].h - (a[i].s - k)][0] + a[i].w);
        }
      }
    }
  }
  std::cout << dp[h][s] << std::endl;
  return 0;
}
