// 自分の得意な言語で
// Let's チャレンジ！！

// clang-format off
#include <algorithm>
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
template <std::size_t MAX_SIZE_EDGE, class TData = int> struct graph {
  struct node {
    int to{};
    TData data{};
    node(int t, TData d): to(t), data(d){}
  };
  std::array<std::list<node>, MAX_SIZE_EDGE> edges;

  graph() {}

  void add_edge(int u, int v, TData data = TData{}) {
    edges[u].emplace_back(v, data);
  }
  void add_biedge(int u, int v, TData data = TData{}) {
    add_edge(u, v, data), add_edge(v, u, data);
  }
  void clear() { edges.fill(std::list<node>()); }
  std::list<node> &from(std::size_t idx) noexcept { return (*this)[idx]; }
  std::list<node> &operator[](std::size_t idx) noexcept { return edges[idx]; }
};
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
const int maxn = 3e5 + 17;
const int maxw = 1e9;
int n;

int d[maxn];
graph<maxn> g;
bool vis[maxn];
ll dp[maxn][2];

void dfs(int x) {
  vis[x] = true;

  std::vector<std::pair<int, int>> vec;
  for (auto &[v, w] : g[x]) {
    if (vis[v])
      continue;
    dfs(v);
    if (d[v] == 0 || w <= 0) {
      dp[x][0] += dp[v][0];
      dp[x][1] += dp[v][0];
    } else {
      vec.push_back({w, v});
    }
  }

  std::sort(vec.begin(), vec.end(),
            [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
              return dp[lhs.second][1] + lhs.first - dp[lhs.second][0] >
                     dp[rhs.second][1] + rhs.first - dp[rhs.second][0];
            });

  int cdx = 0;
  for (int i = 0; i < vec.size(); i++) {
    auto &[w, v] = vec[i];
    if (d[v] == 0)
      continue;

    if (dp[v][1] + w > dp[v][0]) {
      cdx++;
      if (cdx <= d[x] - 1) {
        dp[x][1] += dp[v][1] + w;
      } else {
        dp[x][1] += dp[v][0];
      }
      if (cdx <= d[x]) {
        dp[x][0] += dp[v][1] + w;
      } else {
        dp[x][0] += dp[v][0];
      }
    } else {
      dp[x][1] += dp[v][0];
      dp[x][0] += dp[v][0];
    }
  }
}

int inde[maxn];

void solve(const std::size_t testcase) {
  read(n);
  rep1(i, n) { read(d[i]); }
  rep(i, n - 1) {
    int u, v, w;
    read(u, v, w);
    g.add_biedge(u, v, w);
    inde[u]++;
  }
  int rt = std::min_element(inde + 1, inde + 1 + n) - inde;
  dfs(rt);
  std::cout << std::max(dp[rt][0], dp[rt][1]);
}
