// Problem: P3379 【模板】最近公共祖先（LCA）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3379
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// clang-format off
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); }
void solve(const std::size_t testcase);

int main() {
  std::size_t t = 1;
  // read(t);
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  for(std::size_t i = 1; i <= t; i++) solve(t);
  return 0;
}
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#define TO_STRING_IMPL(type) void _to_string_##type(std::ostream& buffer, const type& value); std::ostream& operator<<(std::ostream& buff, const type& value){ _to_string_##type(buff, value); return buff; }\
  void _to_string_##type(std::ostream& buffer, const type& value)
#ifdef LOCAL
#define debug_do if(true)
#else
#define debug_do if(false)
#endif
#define debug(...) debug_do std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)

// clang-format on

const int maxn = 5e5 + 17;

struct Edge{
  int to, next;
} e[maxn * 2 + 1];

int head[maxn], eid = 0;

void add_edge(int u, int v){
  e[++eid].next = head[u];
  e[eid].to = v;
  head[u] = eid;
}
void add_biedge(int u, int v){
  add_edge(u, v);
  add_edge(v, u);
}

int N, M, S;


int st[maxn][21];
int parent[maxn];
int depth[maxn];
void dfs(int x, int fa){
  parent[x] = fa;
  depth[x] = depth[fa] + 1;
  for(int i = head[x]; i; i = e[i].next){
    const int v = e[i].to;
    if(v == fa) continue;
    dfs(v, x);
  }
}
void build_multiply(){
  for(int i = 1; i <= N; i++){
    st[i][0] = parent[i];
  }
  for(int j = 1; j < 21; j++){
    for(int i = 1; i <= N; i++){
      st[i][j] = st[st[i][j-1]][j-1];
    }
  }
}
int LCA(int x,int y){
  if(depth[x] > depth[y]) std::swap(x, y);
  for(int j = 20; j >= 0; j--){
    if(depth[st[y][j]] >= depth[x]){
      y = st[y][j];
    }
  }
  debug(x, y, depth[x], depth[y]);
  if(x == y) return x;
  for(int j = 20; j >= 0; j--){
    if(st[x][j] != st[y][j]){
      x = st[x][j];
      y = st[y][j];
    }
  }
  return st[x][0];
}

void solve(const std::size_t testcase){
  read(N, M, S);
  for(int i = 0; i < N-1; i++){
    int x, y;
    read(x, y);
    add_biedge(x, y);
  }
  dfs(S,0);
  build_multiply();
  
  for(int i = 0; i < M; i++){
    int a,b;
    read(a,b);
    std::cout << LCA(a,b) << "\n";
  }
  
}