#include <bits/stdc++.h>
using ll = long long;
const int modd = 99999;

// clang-format off
// ------------ Minify with Regex "^\s*(?!#)(.*)\n" -> " " ------------
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#ifndef ONLINE_JUDGE
#define debug_do if(true)
#else
#define debug_do if(false)
#endif
#define debug(...) debug_do std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
// clang-format on

int qpow(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1)
      ans = (ans * a) % modd;
    n >>= 1;
    a = (a * a) % modd;
  }
  return ans % modd;
}

int factor(int x) {
  int ans = 1;
  for (int i = 1; i <= x; i++) {
    ans *= i;
    ans %= modd;
  }
  return ans;
}

int A(int n, int t) {
  int ans = 1;
  for (int i = t; i <= n; i++) {
    ans *= i;
    ans %= modd;
  }
  return ans;
}
int C(int n, int m) { return A(n, m) * qpow(A(m, m), modd - 2) % modd; }

void solve() {
  int L;
  std::cin >> L;
  int ans = 0;
  if (L == 1) {
    ans = 5;
  } else if (L == 2) {
    ans = 33;
  } else {
    for (int b = 0; b <= L; b++) {
      int kb = 1; //id

      for (int vb = 0; vb <= b; vb++) {
        for (int hb = 0; hb + vb <= b; hb++) {
          if (hb * 2 + kb >= L)
            continue;
          kb *= qpow(2, hb);


        }
      }
      debug(L, b, kb);
      debug(L-b);

      if (L - b > 1) {
        ans += kb * qpow(4, L - b);
        ans %= modd;
      }
    }
  }
  std::cout << ans << "\n";
}
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
