// 自分の得意な言語で
// Let's チャレンジ！！

// clang-format off
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); }
void solve(const std::size_t testcase);
#define rep(NAME, MAX) for(decltype(MAX) NAME = 0; NAME < MAX; NAME++)
#define rep1(NAME, MAX) for(decltype(MAX) NAME = 1; NAME <= MAX; NAME++)
#define repv0(NAME, START) for(decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for(decltype(START) NAME = START; NAME >= 1; NAME--)
int main() {
  std::size_t t = 1;
  // read(t);
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  rep1(i, t) solve(t);
  return 0;
}
// clang-format on

int n, m;
int a[110], b[110];
ll dp[2][100000][110];

void solve(const std::size_t testcase) {
  read(n, m);
  rep1(i, n) { read(a[i], b[i]); }
  std::memset(dp, 0xf3, sizeof(dp));
  dp[0][5200][0] = 0;
  rep1(i, n) {
    for (int j = -2600; j <= 2600; j++) {
      for (int k = 0; k <= n; k++) {
        dp[i % 2][j + 5200][k] =
            std::max(dp[(i - 1) % 2][j + 5200][k],
                     dp[(i - 1) % 2][j - b[i] + 5200][k] + a[i]);
        dp[i % 2][j + 5200][k] = std::max(
            dp[i % 2][j + 5200][k], dp[(i - 1) % 2][j + b[i] + 5200][k] + a[i]);
          dp[i%2][j+5200] = std::max(dp[i % 2][j +5200][k], dp[(i-1) % 2][j - 2 * b] +)
      }
    }
  }
}
