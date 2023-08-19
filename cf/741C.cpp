// Problem: C. Arpa’s overnight party and Mehrdad’s silent entering
// Contest: Codeforces - Codeforces Round 383 (Div. 1)
// URL: https://codeforces.com/problemset/problem/741/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)
// clang-format off
#include <bits/stdc++.h> 
using i16 = short; using i32 = int; using i64 = long long; using u16= unsigned short; using u32 = unsigned int; using u64 = unsigned long long;using f32 = float; using f64 = double; using f128 = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); } template <typename T> inline void reads(T begin, T end){ while(begin != end) { read(*begin); begin++; } }
void solve(); void init();
int TESTCASE = 1; int main() {
  init();
  for(int i = 1; i <= TESTCASE; i++){
  	solve();
  	if(i != TESTCASE) std::cout << "\n";
  }
  return 0;
}
#define MultiTest read(TESTCASE)
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
#define int i64
// using i128 = __int128;

int n;
const int maxn = 1e5 + 17;
struct Edge {
  int next, to;
} e[4 * maxn + 17];

int head[2*maxn+17], eid = 0;

void add_edge(int u, int v) {
  e[eid].to = v;
  e[eid].next = head[u];
  head[u] = eid++;
}

void add_biedge(int u, int v) {
  add_edge(u, v);
  add_edge(v, u);
}

void init() {
  std::memset(head, -1, sizeof(head));
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  // std::cout.tie(nullptr); MultiTest;
}

int color[maxn*2+17];

bool dfs(int x, int c) {
  color[x] = c;
  debug(x, c);
  for (int i = head[x]; ~i; i = e[i].next) {
    const int v = e[i].to;
    debug(v, (c^1), color[v]);
    if (color[v] == c) return false;
    if (color[v] != 0) continue;
    
    if (!dfs(v, c^1)) {
      return false;
    }
  }
  return true;
}
using pii = std::pair<int, int>;
void solve() {
  read(n);
  std::vector<pii> p;
  
  for (int i = 1; i < 2 * n; i += 2) {
    add_biedge(i, i + 1);
  }
  
  rep(i, n) {
    int u, v;
    read(u, v);
    p.pb({u, v});
    add_biedge(u, v);
  }
 

  for (int i = 1; i <= 2 * n; i++) {
    if (color[i] == 0) {
      if (!dfs(i, 3)) {
        std::cout << "-1";
        return;
      }
    }
  }

  for (int i = 0; i < p.size(); i++) {
    std::cout << color[p[i].first] - 1 << " " << color[p[i].second] - 1 << "\n";
  }
}
