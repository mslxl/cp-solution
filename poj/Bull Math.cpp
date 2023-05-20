// Problem: Bull Math
// Contest: Virtual Judge - POJ
// URL: https://vjudge.net/problem/POJ-2389
// Memory Limit: 64 MB
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
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
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

std::vector<int> cache[10];

std::vector<int> c2i(std::string &str) {
  std::vector<int> seq(str.size(), 0);
  for (int i = 0; i < str.size(); i++) {
    seq[i] = str[i] - '0';
  }
  std::reverse(all(seq));
  return seq;
}

void prod(std::vector<int> &num, int p) {
  num.pb(0);
  num.pb(0);
  cache[p].resize(num.size());

  for (int i = 0; i < cache[p].size(); i++) {
    cache[p][i] += (num[i] * p) % 10;
    if (i + 1 < cache[p].size()) {
      cache[p][i + 1] += (num[i] * p) / 10;
      if (cache[p][i] >= 10) {
        cache[p][i + 1] += cache[p][i] % 10;
        cache[p][i] /= 10;
      }
    }
  }  
}

std::vector<int> ans(90);

void plus(int p, int offset){
  for(int i = offset; i - offset < cache[p].size(); i++){
    const int b = cache[p][i-offset];
    ans[i] += b;
    ans[i+1] = ans[i] / 10;
    ans[i] %= 10;
  }
}


void solve(const std::size_t testcase) {
  std::string t;
  std::cin >> t;
  std::vector<int> a = c2i(t);
  std::cin >> t;
  std::vector<int> b = c2i(t);

  for (int i = 0; i <= 9; i++) {
    prod(a, i);
    debug_do {
      for (int j = 0; j < cache[i].size(); j++) {
        std::cerr << (int)cache[i][j];
      }
      std::cerr << std::endl;
    }
  }
  for(int i = 0; i < b.size(); i++){
    plus(b[i], i);
  } 
}
