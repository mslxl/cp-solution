// clang-format off
// 自分の得意な言語で
// Let's チャレンジ！！
#include <algorithm>
#include <bits/stdc++.h> 
#include <limits>
using ll = long long; using ul = unsigned long long; using ld = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); }
void solve(const std::size_t testcase);
#define rep(NAME, MAX) for(decltype(MAX) NAME = 0; NAME < MAX; NAME++)
#define rep1(NAME, MAX) for(decltype(MAX) NAME = 1; NAME <= MAX; NAME++)
#define repv0(NAME, START) for(decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for(decltype(START) NAME = START; NAME >= 1; NAME--)
int main() {
  std::size_t t = 1;
  // std::cin >> t;
  rep1(i, t) solve(t);
  return 0;
}
// clang-format on
#define int ll
int n, m;
std::vector<ll> seq;

// coding here
void solve(const std::size_t testcase) {
  read(n, m);
  seq.resize(n);
  rep(i, n) read(seq[i]);
  std::sort(seq.begin(), seq.end());

  if (m == 0) {
    std::cout << seq[seq.size() - 1] - seq[0];
    return;
  }
  if (n == 1) {
    std::cout << 0;
    return;
  }

  ll ans = std::numeric_limits<ll>::max();
  bool has_ans = false;

  for (int u = 0; u <= m && u < seq.size(); u++) {
    int v;
    if (u * 3 <= m) {
      v = m - 2 * u;
    } else {
      v = (m - u) / 2;
    }
    if (u + v >= seq.size()) {
      ans = 0;
      break;
    } else {
      ans = std::min(ans, seq[seq.size() - v - 1] - seq[u]);
    }
  }
  std::cout << ans;
}
