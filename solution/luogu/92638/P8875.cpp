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
  // std::cin >> t;
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

// coding here
const int modd = 998244353;

const int maxnm = 1e3 + 17;
const int maxrc = 50 + 17;
int n, m;
int r, c;
int a[maxnm][maxnm];
int b[maxrc][maxrc];
ll prefix[maxnm][maxnm];

void solve(const std::size_t testcase) {
  // std::cout<<"hello,world"<<std::endl;
  read(n, m);
  rep1(i, n) {
    rep1(j, m) { read(a[i][j]); }
  }
  read(r, c);
  rep1(i, r) {
    rep1(j, c) { read(b[i][j]); }
  }


  // build prefix table
  rep1(i, n) {
    rep1(j, m) {
      prefix[i][j] =
          prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
      int ir = (i - 1) % r + 1, jc = (j - 1) % c + 1;
      prefix[i][j] += b[ir][jc] * a[i][j];
      prefix[i][j] = (prefix[i][j] + modd) % modd;
    }
  }

  debug_do {
    std::cerr << "A:\n";
    rep1(i, n){
      rep1(j, m){
        std::cerr << a[i][j] << " ";
      }
      std::cerr << "\n";
    }
    std::cerr << "Prefix_table:\n";
    rep1(i, n){
      rep1(j, m){
        std::cerr << prefix[i][j] << " ";
      }
      std::cerr << "\n";
    }
  }

  // query
  int q;
  read(q);
  rep(_i, q) {
    int x1, y1, x2, y2;
    read(x1, y1, x2, y2);
    int ans = prefix[y2][x2] - prefix[y2][x1 - 1] - prefix[y1 - 1][x2] +
              prefix[y1 - 1][x1 - 1];
    std::cout << ans << "\n";
  }
}
