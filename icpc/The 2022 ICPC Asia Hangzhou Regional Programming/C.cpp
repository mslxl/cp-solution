// Problem: C. No Bug No Game
// Contest: Codeforces - The 2022 ICPC Asia Hangzhou Regional Programming
// Contest URL: https://codeforces.com/gym/104090/problem/C Memory Limit: 1024
// MB Time Limit: 1000 ms
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
  // read(t);
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
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
#define int ll
const int maxn = 3e3 + 17;
const int maxk = 3e3 + 17;
int dp[maxn][maxk][2];

std::vector<int> item[maxn];
int n, v;

void solve(const std::size_t testcase) {
  std::cin >> n >> v;
  
  int total_v = 0;
  
  for (int i = 1; i <= n; i++) {
    auto &bk = item[i];
    int num;
    std::cin >> num;
    total_v += num;
    bk.resize(num);
    for (int j = 0; j < num; j++) {
      std::cin >> bk[j];
    }
    // debug(i, sum[i], bk);
  }
  if(total_v <= v){
    int ans = 0;
    for(int i = 1; i <= n; i++){
      ans += item[i][item[i].size()-1];
    }
    std::cout << ans;
    return;
  }
  
  std::memset(dp, -0x3f, sizeof(dp));
  dp[0][0][0] = dp[0][0][1] = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = item[i].size() - 1;
    for (int j = 0; j <= v; j++) {
      dp[i][j][0] = dp[i - 1][j][0];
      dp[i][j][1] = dp[i - 1][j][1];
      if (j - int(item[i].size()) >= 0) {
        // non-full
        dp[i][j][0] = std::max(dp[i - 1][j][0],
                               dp[i - 1][j - item[i].size()][0] + item[i][cnt]);
        debug(i, j, item[i].size(), dp[i][j][0]);
        dp[i][j][1] = std::max(dp[i - 1][j][1],
                               dp[i - 1][j - item[i].size()][1] + item[i][cnt]);
      }
      // full

      for (int k = 1; k <= item[i].size(); k++) {
        if (j - k >= 0) {
          dp[i][j][0] =
              std::max(dp[i][j][0], dp[i - 1][j - k][1] + item[i][k - 1]);
        }
      }
    }
  }
  debug(dp[n][v][0], dp[n][v][1]);
  std::cout << std::max(dp[n][v][0], dp[n][v][1]);
}