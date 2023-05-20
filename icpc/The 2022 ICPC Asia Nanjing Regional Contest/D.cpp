// Problem: D. Chat Program
// Contest: Codeforces - The 2022 ICPC Asia Nanjing Regional Contest
// URL: https://codeforces.com/gym/104128/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// clang-format off
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
using pii = std::pair<int,int>; using pli = std::pair<ll, int>; using ull = std::pair<ll,ll>;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &ans){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; ans=(c&15); while(isdigit(c=getchar())) ans= (ans<<1) + (ans<<3) + (c&15); ans*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); }
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

const int maxn = 2e5 + 17;

int n, k, m;
ll a[maxn], c, d;

int pre[maxn];

bool check(ll ans) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) cnt += a[i] >= ans ? 1 : 0;
  if (cnt >= k) return true;

  std::memset(pre, 0, sizeof(int) * (n + 17));
  for (int i = 1; i <= n; i++)
    if (a[i] < ans) {
      int right_boundary = std::min(m - 1, i - 1);
      ll mx = a[i] + c + d * right_boundary;
      if (mx < ans) continue;
      pre[std::max(m, i)]++;
      ll mn = a[i] + c;
      if (mn >= ans)
        pre[std::min(n + 1, i + m)]--;
      else {
        ll t = ans - a[i] - c;
        int pos;
        if (t % d == 0)
          pos = t / d - 1;
        else
          pos = t / d;
        pre[std::min(n + 1, i + m - pos - 1)]--;
      }
    }

  for (int i = m; i <= n; i++) {
    cnt += pre[i];
    if (cnt >= k) return true;
  }
  return false;
}

void solve(std::size_t testcase) {
  std::cin >> n >> k >> m >> c >> d;
  for (int i = 1; i <= n; i++) std::cin >> a[i];

  ll L = 0, R = 1e32;
  ll ans;
  while (L <= R) {
    ll mid = L + (R-L)/2;
    if (check(mid)){
       ans = mid;
       L = mid + 1;
    }else{
      R = mid - 1;
    }
  }
  std::cout << ans;
}