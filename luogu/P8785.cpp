// Problem: P8785 [蓝桥杯 2022 省 B] 扫雷
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8785
// Memory Limit: 128 MB
// Time Limit: 1000 ms
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
#define TO_STRING_IMPL(type) \
  void _to_string_##type(std::ostream& buffer, const type& value); \
  std::ostream& operator<<(std::ostream& buff, const type& value){\
    _to_string_##type(buff, value);\
    return buff;\
  }\
  void _to_string_##type(std::ostream& buffer, const type& value)
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#ifdef LOCAL
#define debug_do if(true)
#else
#define debug_do if(false)
#endif
#define debug(...) debug_do std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)

// clang-format on
struct range{
  int x = 0;
  int y = 0;
  int r = 0;
  bool is_bomb(const range& rhs) const {
    int distance = std::sqrt(std::pow(x - rhs.x, 2) + std::pow(y - rhs.y, 2));
    return distance <= r;
  }
  
  bool operator<(const range& rhs) const {
    return x < rhs.x;
  }
};

TO_STRING_IMPL(range){
  buffer << "(x = " << value.x << ", y = " << value.y << ", r = " << value.r << ")";
}

const int maxn = 5e4 + 17;
range mine[maxn];
range rocket[maxn];
bool flag[maxn];
int n,m;

int ans = 0;

void dfs(const range& lit){
  range* left = std::lower_bound(mine + 1, mine + 1 + n, lit, [](const range& element, const range& value){
    return element.x <value.x - value.r;
  });
  range* right = std::lower_bound(mine + 1, mine + 1 + n, lit, [](const range& element, const range& value){
    return element.x < value.x + value.r;
  });
  while(right-> x < lit.x + lit.r && right < mine + 1 + n) right++;
  for(auto iter = left; iter < right; iter++){
    int idx = iter - mine;
    if(iter->x > lit.x + lit.r) continue;
    if(iter->x < lit.x - lit.r) continue;
    if(flag[idx]) continue;
    if(lit.is_bomb(*iter)){
      flag[idx] = true;
      debug("litup", *iter);
      ans++;
      dfs(*iter);
    }
  }
}


void solve(const std::size_t testcase){
  read(n,m);
  for(int i = 1; i <= n; i++){
    read(mine[i].x, mine[i].y, mine[i].r);
  }

  for(int i = 1; i <= m; i++){
    read(rocket[i].x, rocket[i].y, rocket[i].r);
  }
  std::sort(mine + 1, mine + 1 + n);
  std::sort(rocket + 1, rocket + 1 + n);
  
  for(int i = 1; i <= m && ans < n; i++){  
    debug("rocket", i);
    dfs(rocket[i]);
  }
  std::cout << ans;
}