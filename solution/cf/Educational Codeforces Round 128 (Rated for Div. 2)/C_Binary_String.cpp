#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#undef Local
#endif
#ifdef Local
#define tout \
  if (1)     \
  std::cerr
#else
#define tout \
  if (0)     \
  std::cerr
#endif
using ll = long long;
using ull = unsigned long long;
#define rep(i, s, e) for (int i = s; i < e; i++)
#define fors(i, s, e) rep(i, s, e + 1)

const int maxn = 2 * 1e5;
int dp[maxn + 17][2][2];

void solve() {
  std::string str;
  std::cin >> str;
  int num_zero = 0, num_del_one = 0;
  for (const char& ch : str) {
    if (ch == '0')
      num_zero++;
  }
  dp[0][0][0] = num_zero;
  dp[0][0][1] = 0;

}

int main() {
#ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
