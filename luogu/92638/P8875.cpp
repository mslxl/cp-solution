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

#define int ll
template <typename T> using vvector = std::vector<std::vector<T>>;
const int modd = 998244353;

void solve(const std::size_t testcase) {
  int n, m, r, c;
  read(n, m);
  vvector<int> A(n + 1, std::vector<int>(m + 1));
  rep1(i, n) rep1(j, m) read(A[i][j]);
  read(r, c);
  vvector<int> B(r + 1, std::vector<int>(c + 1));
  rep1(i, r) rep1(j, c) read(B[i][j]);

  vvector<int> pre(A);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int irj = i - r >= 0 ? pre[i - r][j] : 0;
      irj %= modd;
      int ijc = j - c >= 0 ? pre[i][j - c] : 0;
      ijc %= modd;
      int irjc = (i - r) >= 0 && (j - c) >= 0 ? pre[i - r][j - c] : 0;
      irjc %= modd;
      pre[i][j] = (pre[i][j] + irj) % modd;
      pre[i][j] = (pre[i][j] + ijc) % modd;
      pre[i][j] = (pre[i][j] - irjc + modd) % modd;
    }
  }

  debug("Done");
  debug(n, m, r, c);
  int q;
  read(q);
  rep(i, q) {
    int x1, y1, x2, y2;
    read(x1, y1, x2, y2);
    debug(x1, y1, x2, y2);
    int ans = 0;
    for (int i = 1; i <= std::min(r, x2 - x1 + 1); i++) {
      for (int j = 1; j <= std::min(c, y2 - y1 + 1); j++) {
        if (B[i][j] == 0) {
          debug(i, j);
          int rx1 = x1 + i - 1;
          int rx2 = rx1 + (x2 - rx1) / r * r;
          int ry1 = y1 + j - 1;
          int ry2 = ry1 + (y2 - ry1) / c * c;
          debug(rx1, rx2, ry1, ry2);
          debug(rx1 - c, ry2 - r);

          int ret = pre[rx2][ry2];
          int rx1r = rx1 - r >= 0 ? pre[rx1 - r][ry2] : 0;
          int ry1c = ry1 - c >= 0 ? pre[rx2][ry1 - c] : 0;
          int rx1rry1c =
              rx1 - r >= 0 && ry1 - c >= 0 ? pre[rx1 - r][ry1 - c] : 0;

          ret = (ret - rx1r + modd) % modd;
          ret = (ret - ry1c + modd) % modd;
          ret = (ret  + rx1rry1c) % modd;
          ans = (ans + ret) % modd;
        }
      }
    }
    std::cout << ans << "\n";
  }
}
