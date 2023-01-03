// clang-format off
// 自分の得意な言語で
// Let's チャレンジ！！
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
  rep1(i, t) solve(t);
  return 0;
}
// ------------ Minify with Regex "^\s*(?!#)(.*)\n" -> " " ------------
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
#else
#define debug(...) do {} while (0)
#endif
// clang-format on

ll group_index_maxk(ll n) { return 1 + 3 * n + 2 * n * n; }

// coding here
void solve(const std::size_t testcase) {
  debug("----------");
  ll k;
  read(k);
  if (k == 1) {
    std::cout << 0 << "\n";
    return;
  }

  ll l = 1, r = 2e9;
  ll group_idx;
  while (l <= r) {
    group_idx = l + (r - l) / 2;
    debug(group_idx);
    ll maxk = group_index_maxk(group_idx);
    ll mink = group_index_maxk(group_idx - 1)+1;
    if (mink <= k && k <= maxk)
      break;
    if (maxk < k) {
      l = group_idx + 1;
    } else if (k < mink) {
      r = group_idx - 1;
    }
  }

  ll group_min_k = group_index_maxk(group_idx - 1) + 1;
  ll group_max_k = group_index_maxk(group_idx);
  ll group_peak_ak = group_idx;
  ll group_mid_k = group_min_k + (group_max_k - group_min_k) / 2;
  ll group_peak_span = (group_mid_k - group_min_k) / 2;
  ll top_peak_k = group_min_k + group_peak_span;
  ll bottom_peak_k = group_mid_k + group_peak_span;
  debug(k);
  debug(group_idx);
  debug(group_min_k, group_max_k, group_mid_k);
  debug(top_peak_k, bottom_peak_k);

  if (k == group_min_k) {
    std::cout << 0 << "\n";
  } else if (k > group_mid_k) {
    if (k > bottom_peak_k) {
      std::cout << -group_idx + (k - bottom_peak_k) << "\n";
    } else {
      std::cout << -(k - group_mid_k) << "\n";
    }
  } else {
    if (k > top_peak_k) {
      std::cout << group_idx - (k - top_peak_k) << "\n";
    } else {
      std::cout << k - group_min_k << "\n";
    }
  }
}
