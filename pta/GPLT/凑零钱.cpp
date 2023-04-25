// clang-format off
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
using pii = std::pair<int,int>; using pli = std::pair<ll, int>; using ull = std::pair<ll,ll>;
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
const int maxn = 1e4 + 17;
const int maxv = 100 + 17;
int N, M;
int V[maxn];

int dp[maxv];
std::tuple<int,int,int> fa[maxn][maxv];
void solve(const std::size_t testcase){
  read(N, M);
  
  for(int i = 1; i <= N; i++) read(V[i]);
  std::sort(V+1, V+ 1 + N, std::greater<int>());
  
  dp[0] = 0;
  for(int j = 1; j <= M; j++){
    dp[j] = -0x3f3f3f3f;
  }

  
  for(int i = 1; i <= N; i++){
    for(int j = maxv; j >= V[i]; j--){
      if(dp[j-V[i]] + V[i] >= dp[j]){
        dp[j] = dp[j - V[i]] + V[i];
        fa[i][j] = std::make_tuple(i-1, j-V[i], V[i]);
      }else{
        fa[i][j] = std::make_tuple(i-1, j, 0);
      }
    }
  }
  std::vector<int> use;
  
  for(int i = N, j = M; i != 0 && j != 0; ){
    int v;
    std::tie(i, j, v) = fa[i][j];
    if(v != 0){
      use.push_back(v);
    }
  }
  
  std::sort(use.begin(), use.end());
  if(dp[M] == M){
    std::cout << use[0];
    for(int i = 1; i < use.size(); i++){
      std::cout << " " << use[i];
    }
  }else{
    std::cout << "No Solution";
  }
}