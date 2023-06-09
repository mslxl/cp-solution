// Problem: P8803 [蓝桥杯 2022 国 B] 费用报销
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8803
// Memory Limit: 128 MB
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
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
// clang-format on

#define int ll
const int maxn = 1e3 + 17;
const int maxm = 5e3 + 17;
int N, M, K;
int days[13];
int pre_days[13];

int md2d(int m, int d){
  return pre_days[m-1] + d;
}

struct T{
  int days, value;
  bool operator<(const T& rhs) const {
    return days < rhs.days;
  }
} t[maxn];

int last[maxn];
int dp[maxn][maxm];

void solve(const std::size_t testcase) {
  days[1] = days[3] = days[5] = days[7] = days[8] = days[10] = days[12] = 31;
  days[4] = days[6] = days[9] = days[11] = 30;
  days[2] = 28;
  for(int i = 1; i < 13; i++) pre_days[i] = pre_days[i-1] + days[i];
  
  read(N, M, K);
  rep1(i, N){
    int m, d;
    read(m, d);
    t[i].days = md2d(m, d);
    read(t[i].value);
  }
  std::sort(t + 1, t + 1 + N);
  for(int i = 1; i <= N; i++){
    for(int j = i-1; j >= 0; j--){
      if(t[i].days - t[j].days >= K){
        last[i] = j;
        break;
      }
    }
  }
  debug_do {
    rep1(i, N) std::cerr << last[i] << " ";
    std::cerr << std::endl;
  }
  for(int i = 1; i <= N; i++){
    for(int j = 0; j <= M; j++){
      if(j - t[i].value >= 0){
        dp[i][j] = std::max(
          dp[i-1][j],
          dp[last[i]][j - t[i].value] + t[i].value
        );
      } else {
        dp[i][j] = dp[i-1][j];
      }
      debug(i, j, dp[i][j]);
    }
  }
  
  

  std::cout << dp[N][M];
}
