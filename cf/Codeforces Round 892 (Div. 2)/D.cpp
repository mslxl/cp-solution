// Problem: D. Andrey and Escape from Capygrad
// Contest: Codeforces - Codeforces Round 892 (Div. 2)
// URL: https://codeforces.com/contest/1859/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)
// clang-format off
#include <bits/stdc++.h> 
using i16 = short; using i32 = int; using i64 = long long; using u16= unsigned short; using u32 = unsigned int; using u64 = unsigned long long;using f32 = float; using f64 = double; using f128 = long double;
using pii = std::pair<i32, i32>; using pll = std::pair<i64, i64>; using pil = std::pair<i32, i64>; using pli = std::pair<i64, i32>;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); } template <typename T> inline void reads(T begin, T end){ while(begin != end) { read(*begin); begin++; } }
void solve(); void init();
int TESTCASE = 1; int main() { init(); for(int i = 1; i <= TESTCASE; i++){ solve(); if(i != TESTCASE) std::cout << "\n"; } return 0;}
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

// using i128 = __int128;
void init() {
  //read(TESTCASE);
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  std::cout.tie(nullptr); std::cin >> TESTCASE;
}
void solve() {
  int n;
  std::cin >> n;
  std::vector<pii> a(n);
  std::vector<int> b;
  for (int i = 0; i < n; i++) {
    int l, r, x, y;
    std::cin >> l >> r >> x >> y;
    a[i] = {l, y};
    b.emplace_back(l), b.emplace_back(y);
  }
  std::sort(a.begin(), a.end());

  int q;
  std::cin >> q;
  std::vector<int> que(q + 1);
  for (int i = 1; i <= q; i++) {
    std::cin >> que[i];
    b.emplace_back(que[i]);
  }

  std::sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());

  std::map<int, int> mp;

  auto record = [&](int x) {
    int rec = x;
    x = std::lower_bound(b.begin(), b.end(), x) - b.begin();
    mp[x] = rec;
    return x;
  };

  for (int i = 0; i < n; i++) {
    a[i].first = record(a[i].first);
    a[i].second = record(a[i].second);
  }
  for (int i = 1; i <= q; i++) que[i] = record(que[i]);
  const int INF = maxnum(i32);
  int right = INF, left = -1;
  std::vector<pii> e;
  for (auto [l, r] : a) {
    if (l > right) {
      if (right != INF) e.emplace_back(left, right);
      left = -1;
    }
    if (left == -1) {
      left = l, right = r;
      continue;
    }

    left = std::min(left, l);
    right = std::max(right, r);
  }
  if (left != -1) e.emplace_back(left, right);
  std::sort(e.begin(), e.end());

  std::vector<int> ans(b.size() + 1);
  for (int i = 0, id = 0; i <= b.size(); i++) {
    if (id < e.size() && i == e[id].first) {
      for (int j = i; j <= e[id].second; j++) ans[j] = e[id].second;
      i = e[id].second;
      id++;
    }
    ans[i] = i;
  }

  for (int i = 1; i <= q; i++) std::cout << mp[ans[que[i]]] << " ";
}