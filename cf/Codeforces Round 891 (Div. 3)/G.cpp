// Problem: G. Counting Graphs
// Contest: Codeforces - Codeforces Round 891 (Div. 3)
// URL: https://codeforces.com/contest/1857/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)
// clang-format off
#include <bits/stdc++.h> 
using i16 = short; using i32 = int; using i64 = long long; using u16= unsigned short; using u32 = unsigned int; using u64 = unsigned long long;using f32 = float; using f64 = double; using f128 = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); } template <typename T> inline void reads(T begin, T end){ while(begin != end) { read(*begin); begin++; } }
void solve();
int main() {
  solve();
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
#define mtt int __T; std::cin >> __T; for(std::size_t testcase = 1; testcase <= __T; testcase++, std::cout << "\n")
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

const int maxn = 2e5 + 17;
const int modd = 998244353;

int fa[maxn], sz[maxn], rk[maxn];

struct edge {
  i64 u, v, w;
  bool operator<(const edge &rhs) const { return w < rhs.w; }
};

int find(int x) {
  while (fa[x] != x) x = fa[x];
  return x;
}
void join(int x, int y) {
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(rk[x] > rk[y]){
    fa[y] = x;
    sz[x] += sz[y];
  }else if(rk[x] < rk[y]){
    fa[x] = y;
    sz[y] += sz[x];
  }else{
    fa[x] = y;
    rk[y]++;
    sz[y]+=sz[x];
  }
}

template <typename A, typename BaseT>
typename std::enable_if<std::is_integral<BaseT>::value, A>::type qpow(
    A a, BaseT n, BaseT modd) {
  decltype(a) ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % modd;
    n >>= 1;
    a = (a * a) % modd;
  }
  return ans % modd;
}

void solve() {
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  // std::cout.tie(nullptr);
  mtt {
    int n, S;
    read(n, S);
    for (int i = 0; i <= n; i++) {
      fa[i] = i;
      sz[i] = 1;
    }
    std::vector<edge> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
      std::cin >> a[i].u >> a[i].v >> a[i].w;
    }
    i64 ans = 1;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
      i64 szu = sz[find(a[i].u)];
      i64 szv = sz[find(a[i].v)];

      ans = ans * qpow(S - a[i].w + 1, szu * szv - 1, modd) % modd;
      join(a[i].u, a[i].v);
    }
    std::cout << ans;
  }
}
