// Problem: A Chess Game
// Contest: Virtual Judge - HDU
// URL: https://vjudge.net/problem/HDU-1524
// Memory Limit: 32 MB
// Time Limit: 1000 ms
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
  // read(t); // std::cin >> t;
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
// clang-format on

int n;
const int maxn = 1e4 + 7;

//------ 图定义 ----------
std::vector<int> rev_g[maxn];
std::vector<int> g[maxn];

int rev_indeg[maxn];
int rev_outdeg[maxn];


void clear() {
  for (int i = 0; i < maxn; i++) {
    rev_g[i].clear();
    g[i].clear();
  }
  std::memset(rev_indeg, 0, sizeof(rev_indeg));
  std::memset(rev_outdeg, 0, sizeof(rev_outdeg));
}
void add_edge(int u, int v) {
  rev_g[v].push_back(u);
  g[u].push_back(v);

  rev_indeg[u]++;
  rev_outdeg[v]++;
}

//------ SG ----------

int SG[maxn];
bool mex_vis[maxn];  // 仅用于 SG 函数中求 mex

// 输入节点编号
// 输出 SG 函数中的点编号
int mex(int node) {
  std::memset(mex_vis, false, sizeof(mex_vis));
  for (auto v : g[node]) {  // 遍利能转移到的点
    mex_vis[SG[v]] = true;
  }
  for (int i = 0; i < maxn; i++) {
    if (!mex_vis[i]) return i;
  }
  return -1;
}

void topo_dfs(int u) {
  if (rev_indeg[u] == 0) {
    SG[u] = mex(u);
  } else
    return;

  for (auto v : rev_g[u]) {
    rev_indeg[v]--;
    if (rev_indeg[v] == 0) {
      topo_dfs(v);
    }
  }
}

void sg() {
  std::memset(SG, 0, sizeof(SG));
  for (int i = 0; i < n; i++) {
    if (rev_indeg[i] == 0) {
      SG[i] = 0;  // 无法行动的点的 SG 为 0
      for (auto v : rev_g[i]) {
        rev_indeg[v]--;
        if (rev_indeg[v] == 0) {
          topo_dfs(v);
        }
      }
    }
  }
}

void solve(const std::size_t testcase) {
  while (std::cin >> n) {
    clear();
    for (int i = 0; i < n; i++) {
      int m;
      std::cin >> m;
      for (int j = 0; j < m; j++) {
        int v;
        std::cin >> v;

        add_edge(i, v);
      }
    }
    sg();

    debug_do {
      for (int i = 0; i < n; i++) {
        std::cerr << SG[i] << " ";
      }
      std::cerr << std::endl;
    }

    int k;
    
    while (std::cin >> k && k != 0) {
      int v;
      int sg_sum = -1;
      for (int i = 0; i < k; i++) {
        std::cin >> v;
        if (sg_sum == -1) {
          sg_sum = SG[v];
        } else {
          sg_sum = sg_sum ^ SG[v];
        }
      }
      if(sg_sum == 0){
        std::cout << "LOSE\n"; 
      }else{
        std::cout << "WIN\n";
      }
    }
  }
}
