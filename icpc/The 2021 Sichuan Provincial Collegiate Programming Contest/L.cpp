// Problem: L. Spicy Restaurant
// Contest: Codeforces - The 2021 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/103117/problem/L
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// clang-format off
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
using pii = std::pair<int,int>; using pli = std::pair<ll, int>; using ull = std::pair<ll,ll>;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); }
void solve(const std::size_t testcase);

int main() {
  std::size_t t = 1;
   // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  // read(t);
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
#define pb push_back
#define pf push_front
#define mmax(a,  b) a = std::max(a, (decltype(a)) b);
#define mmin(a, b) a = std::min(a, (decltype(a)) b);

// clang-format on
#define int ll
const int maxn = 1e5 + 17;
struct Edge{
  int to, next;
} e[maxn * 2 + 1];

int head[maxn], eid = 0;

void add_edge(int u, int v){
  e[++eid].next = head[u];
  e[eid].to = v;
  head[u] = eid;
}
void add_biedge(int u,int v){
  add_edge(u, v);
  add_edge(v, u);
}

int n, m, q;
int val[maxn];

int dist[110][maxn];
bool vis[maxn];
void bfs(int accept){
  std::queue<int> qq;
  for(int i = 1; i <= n; i++){
    if(val[i] <= accept){
      qq.push(i);
      dist[accept][i] = 0;
    }
  }

  while(!qq.empty()){
    const int u = qq.front();
    qq.pop();
    if(vis[u]) continue;
    vis[u] = true;
    
    for(int eid = head[u]; eid != 0; eid = e[eid].next){
      const int v = e[eid].to;
      if(!vis[v] && dist[accept][v] > dist[accept][u] + 1){
        dist[accept][v] = dist[accept][u] + 1;
        qq.push(v);
      }
    }
  }
}

void solve(const std::size_t testcase){
  read(n, m, q);
  for(int i = 1; i <= n; i++){
    read(val[i]);
  }
  for(int i = 1; i <= m; i++){
    int u, v;
    read(u, v);
    add_biedge(u, v);
  }

  std::memset(dist, 0x3f, sizeof(dist));
 
  
  for(int i = 1; i <= 100; i++){
    bfs(i);
    std::memset(vis, false, sizeof(vis));
  }
  
  for(int i = 1; i <= q; i++){
    int u, acc;
    read(u, acc);

    int ans = dist[acc][u];
    if(ans >= 0x3f3f3f3f){
      std::cout << -1 << "\n";
    }else{
      std::cout << ans << "\n";
    }
  }
}