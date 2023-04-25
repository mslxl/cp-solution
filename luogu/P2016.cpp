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

const int maxn = 1.5e3 + 17;
int n;
graph<maxn> g;
bool vis[maxn];
int dp[maxn][2];

void dfs(int x){
  vis[x] = true;
  dp[x][1] = 1;
  dp[x][0] = 0;

  for(auto &[v,_]: g[x]){
    if(vis[v]) continue;
    dfs(v);
    dp[x][1] += std::min(dp[v][0], dp[v][1]);
    dp[x][0] += dp[v][1];
  }
}

void solve(const std::size_t testcase) {
  read(n);
  rep(_i, n){
    int i;
    int k;
    read(i,k);

    rep(j, k){
      int r;
      read(r);
      g.add_biedge(i, r);
    }
  }
  dfs(0);
  std::cout << std::min(dp[0][0], dp[0][1]);

}
