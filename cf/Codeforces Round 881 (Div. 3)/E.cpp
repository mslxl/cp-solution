// Problem: E. Tracking Segments
// Contest: Codeforces - Codeforces Round 881 (Div. 3)
// URL: https://codeforces.com/contest/1843/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

// clang-format off
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); } template <typename T> inline void reads(T begin, T end){ while(begin != end) { read(*begin); begin++; } }
void solve(const std::size_t testcase);
int main() {
  std::size_t t = 1;
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  read(t); // std::cin >> t;
  for(std::size_t i = 1; i <= t; i++) solve(t);
  return 0;
}
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#define TO_STRING(type) void _to_string_##type(std::ostream& buffer, const type& value); std::ostream& operator<<(std::ostream& buff, const type& value){ _to_string_##type(buff, value); return buff; }\
  void _to_string_##type(std::ostream& buffer, const type& value)
#ifdef LOCAL
#define debug_do if(true)
#else
#define debug_do if(false)
#endif
#define debug(...) debug_do std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
#define maxnum(type) std::numeric_limits<type>::max()
#define minnum(type) std::numeric_limits<type>::min()
#define pb push_back
#define pf push_front
#define mk std::make_pair
#define mt std::make_tuple
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define all1(x) ++(x).begin(), (x).end()
#define rall1(x) (x).rbegin(), --(x).rend()
#define mmax(a,  b) a = std::max(a, (decltype(a)) b);
#define mmin(a, b) a = std::min(a, (decltype(a)) b);
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
// clang-format on

#define int ll
int n, m;
const int maxn = 1e5 + 17;
int bits[maxn];
int lowbit(int x) { return (-x) & x; }
void add(int i) {
  for (; i < maxn; i += lowbit(i)) {
    bits[i] += 1;
  }
}
int prefix(int i) {
  int sum = 0;
  for (; i > 0; i -= lowbit(i)) {
    sum += bits[i];
  }
  return sum;
}
void solve(const std::size_t testcase) {
  std::memset(bits, 0, maxn);
  read(n, m);
  std::vector<std::pair<int, int>> r;
  r.resize(m);
  rep(i, m) { read(r[i].first, r[i].second); }

  std::sort(all(r));
  r.erase(std::unique(all(r)), r.end());
  debug(r);

  int c;
  read(c);
  std::vector<int> ch(c);
  rep(i, c) read(ch[i]);

  rep(i, c) {
    add(ch[i]);

    auto begin = std::lower_bound(
        all(r), std::make_pair(ch[i], ch[i]),
        [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
          if(rhs.first < lhs.first) {
            return true;
          }
          return false;
          
        });
    for (; begin != r.end(); ++begin) {
      auto &range = *begin;
      debug(ch[i], range);
      if (range.first > ch[i]) break;

      int sum = prefix(range.second) - prefix(range.first - 1);
      int len = range.second - range.first + 1;
      if (len - sum < sum) {
        std::cout << (i + 1) << "\n";
        return;
      }
    }
  }
  std::cout << "-1\n";
}
