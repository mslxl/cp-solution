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
std::unordered_map<char, int> cache;
std::unordered_map<int, char> invcache;
void init_hex2dec() {
  for (int ch = '0'; ch <= '9'; ch++) {
    cache[ch] = ch - '0';
    invcache[ch - '0'] = ch;
  }
  for (int ch = 'A'; ch <= 'F'; ch++) {
    cache[ch] = ch - 'A' + 10;
    invcache[ch - 'A' + 10] = ch;
  }
}

int hex2dec(char h, char l) { return (cache[h] << 4) + cache[l]; }

std::string dec2hex(int dec) {
  std::string ans;
  ans += invcache[dec >> 4];
  ans += invcache[dec & 0b1111];
  return ans;
}

int n;
std::vector<int> img[20 + 17];
using pii = std::pair<int, int>;
std::vector<pii> bucket(256);

char near(int v) {
  int diff = std::numeric_limits<int>::max(), near;
  rep(i, 16) {
    int sub = std::abs(v - bucket[i].second);
    if (sub < diff) {
      diff = sub;
      near = i;
    }
  }
  return invcache[near];
}
struct CMP {
  bool operator()(pii &l, pii &r) {
    if (l.first == r.first) return l.second < r.second;
    return l.first > r.first;
  }
};

void solve(const std::size_t testcase) {
  init_hex2dec();
  std::cin >> n;
  std::string line;
  std::getline(std::cin, line);
  rep(i, n) {
    std::getline(std::cin, line);
    for (int j = 0; j < line.size(); j += 2) {
      int value = hex2dec(line[j], line[j + 1]);
      img[i].pb(value);
      bucket[value].first++;
    }
  }

  for (int i = 0; i <= 255; i++) bucket[i].second = i;

  std::sort(all(bucket), CMP());

  for (int i = 0; i <= 15; i++) {
    // debug(bucket[i].second);
    std::cout << dec2hex(bucket[i].second);
  }
  std::cout << "\n";
  rep(i, n) {
    for (auto num : img[i]) {
      std::cout << near(num);
    }
    std::cout << "\n";
  }
}
