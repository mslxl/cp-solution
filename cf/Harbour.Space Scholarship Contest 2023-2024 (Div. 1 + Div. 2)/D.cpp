// Problem: D. Matrix Cascade
// Contest: Codeforces - Harbour.Space Scholarship Contest 2023-2024 (Div. 1 +
// Div. 2) URL: https://codeforces.com/contest/1864/problem/D Memory Limit: 512
// MB Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)
// clang-format off
#include <bits/stdc++.h> 
using i16 = short; using i32 = int; using i64 = long long; using u16= unsigned short; using u32 = unsigned int; using u64 = unsigned long long;using f32 = float; using f64 = double; using f128 = long double;
using pii = std::pair<i32, i32>; using pll = std::pair<i64, i64>; using pil = std::pair<i32, i64>; using pli = std::pair<i64, i32>;
template<class T> using V = std::vector<T>;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); } template <typename T> inline void reads(T begin, T end){ while(begin != end) { read(*begin); begin++; } }
void solve(); void init();
int TESTCASE = 1; int main() { init(); for(int i = 1; i <= TESTCASE; i++){ solve(); if(i != TESTCASE) std::cout << "\n"; } return 0;}
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#define TO_STRING(type) void _to_string_##type(std::ostream& buffer, const type& value); std::ostream& operator<<(std::ostream& buff, const type& value){ _to_string_##type(buff, value); return buff; }\
  void _to_string_##type(std::ostream& buffer, const type& value)
template<class T> T lowbit(T x) { return (-x) & x; };
template<class T> T fstTrue(T l, T r, std::function<bool(T)> check){ assert(l <= r); while(l < r){ T mid = l + (r - l) / 2; if(check(mid)) r = mid; else l = mid + 1; } return r; }
template<class T> T lstTrue(T l, T r, std::function<bool(T)> check){ assert(l <= r); while(l < r){ T mid = l + (r - l + 1)/2; if(check(mid)) l = mid; else r = mid - 1; } return l; }
template<class T> T gcd(T a, T b) { return std::__gcd(a, b); }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; };
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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define all1(x) ++(x).begin(), (x).end()
#define rall1(x) (x).rbegin(), --(x).rend()
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
template<class R, class A> R mmax(R x, A y){ return std::max(x, (R) y); } template<class R, class A, class... AS> R mmax(R x, A xx, AS... xxs){ return std::max(x, mmax((R)xx, xxs...));  }
template<class R, class A> R mmin(R x, A y){ return std::min(x, (R) y); } template<class R, class A, class... AS> R mmin(R x, A xx, AS... xxs){ return std::min(x, mmin((R)xx, xxs...));  }
using std::cout; using std::cin; using std::endl;
#define endl "\n"
// clang-format on
#define int i64
// using i128 = __int128;
void init() {
  read(TESTCASE);
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  // std::cout.tie(nullptr); std::cin >> TESTCASE;
}
void solve() {
  int n;
  read(n);
  V<V<int>> a(n + 1, V<int>(n + 1)), b(n + 1, V<int>(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char ch;
      std::cin >> ch;
      a[i][j] = ch - '0';
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] ^= b[i][j];                  
      ans += a[i][j];                     
      b[i][j] ^= a[i][j];                  

      a[i][j] ^= b[i][j];                   
      if (i + 1 < n) {                     
        a[i + 1][j] ^= b[i][j];             
        if (j - 1 >= 0) {                   
          b[i + 1][j - 1] ^= b[i][j];       
        } else if (i + 2 < n) {
          b[i + 2][j] ^= b[i][j];           
        }
        if (j + 1 < n) {
          b[i + 1][j + 1] ^= b[i][j];
        } else if (i + 2 < n) {
          b[i + 2][j] ^= b[i][j];
        }
        if (i + 2 < n) {
          b[i + 2][j] ^= b[i][j];
        }
      }
    }
  }
  std::cout << ans;
}
