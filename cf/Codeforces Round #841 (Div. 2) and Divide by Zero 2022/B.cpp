// clang-format off
// 自分の得意な言語で
// Let's チャレンジ！！
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
void solve(const std::size_t testcase);
#define rep(NAME, MAX) for(decltype(MAX) NAME = 0; NAME < MAX; NAME++)
#define rep1(NAME, MAX) for(decltype(MAX) NAME = 1; NAME <= MAX; NAME++)
#define repv0(NAME, START) for(decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for(decltype(START) NAME = START; NAME >= 1; NAME--)
int main() {
  std::ios::sync_with_stdio(false);
  std::cout.tie(nullptr);
  std::cin.tie(nullptr);
  std::size_t t = 1;
  std::cin >> t;
  rep1(i, t) solve(t);
  return 0;
}
// clang-format on
const ul modd = 1e9 + 7;

#define UseCache

// clang-format off
ul qpow(ul a, ul n){
    ul ans = 1; 
    while (n){
        if (n & 1) ans = (ans * a) % modd; 
        n >>= 1;
        a = (a * a) % modd;
    }
    return ans % modd;
}
// clang-format on


// coding here
void solve(const std::size_t testcase) {
  ul n;
  std::cin >> n;
  ll ans = n * (4 * n - 1) % modd * (n + 1) % modd ;
  ans = ans % modd * 337 % modd;
  std::cout << ans << "\n";
  // std::cout << calc(n) % modd << "\n";
}
