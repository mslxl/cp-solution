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
  read(t);
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  rep1(i, t) solve(t);
  return 0;
}
// clang-format on

ll ans1(ll n , const std::vector<ll> &seq) {
  std::vector<ll> ord(seq);
  if (seq[n - 1] == n - 1) {
    std::sort(ord.begin(), ord.end() - 1);
    ll op = 0;
    rep(i, n - 1) {
      if (ord[i] != seq[i]) {
        op++;
      }
    }
    return std::ceil(1.0 * op / 2);
  } else {
    std::sort(ord.begin(), ord.end());
    ll op = 0;
    rep(i, n) {
      if (ord[i] != seq[i]) {
        op++;
      }
    }
    return std::ceil((1.0 * op) / 2) + 1 ;
  }
}
ll ans2(ll n , const std::vector<ll> &seq) {
  std::vector<ll> ord(seq);
  if (seq[0] == 2) {
    std::sort(ord.begin()+1, ord.end());
    ll op = 0;
    rep1(i, n - 1) {
      if (ord[i] != seq[i]) {
        op++;
      }
    }
    return std::ceil(1.0 * op / 2);
  } else {
    std::sort(ord.begin(), ord.end());
    ll op = 0;
    rep(i, n) {
      if (ord[i] != seq[i]) {
        op++;
      }
    }
    return std::ceil((1.0 * op) / 2) + 1 ;
  }
}

void solve(const std::size_t testcase) {
  ll n;
  read(n);
  std::vector<ll> seq(n);
  rep(i, n) read(seq[i]);
  std::cout << std::min(ans1(n, seq), ans2(n, seq)) << "\n";
}
