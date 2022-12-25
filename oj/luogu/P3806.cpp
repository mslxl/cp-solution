#include <bits/stdc++.h>
// 自分の得意な言語で
// Let's チャレンジ！！

using ll = long long;
using ul = unsigned long long;
using ld = long double;

template <typename T>
inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x) {
  char c;
  T f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-')
      f = -1;
  x = (c & 15);
  while (isdigit(c = getchar()))
    x = (x << 1) + (x << 3) + (c & 15);
  x *= f;
}

template <typename T, typename... A> void read(T &value, A &..._t) {
  read(value);
  read(_t...);
}

#define rep(NAME, MAX) for (decltype(MAX) NAME = 0; NAME < MAX; i++)
#define rep1(NAME, MAX) for (decltype(MAX) NAME = 1; NAME <= MAX; i++)
#define repv0(NAME, START) for (decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for (decltype(START) NAME = START; NAME >= 1; NAME--)

template <std::size_t MAX_SIZE_EDGE, class TData = int> struct graph {
  struct node {
    int to{};
    TData data{};
    node(int t, TData d) : to(t), data(d) {}
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

// ------------ Minify with Regex "^\s*(?!#)(.*)\n" -> " " ------------
// clang-format off
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
#else
#define debug(...) do {} while (0)
#endif
// clang-format on

// main function
#define int ll
const int maxn = 1e4 + 17;
const int maxk = 1e8 + 17;
int n, m;
int sum;
graph<maxn> g;
int root = 0;
int size[maxn];
int maxp[maxn];
std::bitset<maxn> vis;
int judge[maxk];

// gain root
void dfs(int u, int fa) {
  size[u] = 1;
  maxp[u] = 0;
  for (auto &[v, w] : g[u]) {
    if (v == fa || vis[v])
      continue;
    dfs(v, u);
    size[u] += size[v];
    if (size[v] > maxp[u])
      maxp[u] = size[v];
  }
  debug(sum, size[u]);
  maxp[u] = std::max(maxp[u], sum - size[u]);
  if (maxp[u] < maxp[root])
    root = u;
}

int cnt = 0;
int dis[maxn];
int tmp[maxn];
int q[maxn];
std::bitset<maxn> ans;

void get_dis(int u, int f) {
  tmp[cnt++] = dis[u];
  for (auto &[v, w] : g[u]) {
    if (v == f || vis[v])
      continue;
    dis[v] = dis[u] + w;
    get_dis(v, u);
  }
}
void ssolve(int u) {
  std::queue<int> que;
  for (auto &[v, w] : g[u]) {
    if (vis[v])
      continue;
    cnt = 0;
    dis[v] = w;
    get_dis(v, u);
    for (int j = 0; j < cnt; j++) {
      for (int k = 0; k < m; k++) {
        if (q[k] >= tmp[j])
          if(judge[q[k] - tmp[j]]){
            ans[k] = true;
          }
      }
    }

    for(int j = 0; j < cnt; j++){
      que.push(tmp[j]);
      judge[tmp[j]] = true;
    }
  }

  while(!que.empty()){
    judge[que.front()] = false;
    que.pop();
  }
}

void divide(int u) {
  vis[u] = true;
  judge[0] = true;
  ssolve(u);
  for (auto &[v, w] : g[u]) {
    if (vis[v])
      continue;
    root = 0;
    maxp[root] = size[v];
    sum = size[v];
    dfs(v, 0);
    dfs(root, 0);
    debug(root);
    divide(root);
  }
}

void solve(const std::size_t testcase) {
  // coding here
  read(n, m);
  rep(i, n - 1) {
    int u, v, w;
    read(u, v, w);
    g.add_biedge(u, v, w);
  }
  rep(i, m) read(q[i]);

  sum = maxp[0] = n;

  dfs(1, 0);
  dfs(root, 0);
  debug(root);
  divide(root);
  rep(i, m) {
    if (ans[i])
      std::cout << "AYE\n";
    else
      std::cout << "NAY\n";
  }

  // std::cout<<"hello,world"<<std::endl;
}

#ifdef int
#undef int
#endif
int main() {
  std::size_t t = 1;
  // std::cin >> t;
  for (std::size_t i = 1; i <= t; i++) {
    solve(t);
  }

  return 0;
}
