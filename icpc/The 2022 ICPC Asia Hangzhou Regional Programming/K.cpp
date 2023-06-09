// Problem: K. Master of Both
// Contest: Codeforces - The 2022 ICPC Asia Hangzhou Regional Programming Contest
// URL: https://codeforces.com/gym/104090/problem/K
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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
#define int ll
int n, q;
const int maxn = 2e6 + 17;
int sum[maxn];
int tri[maxn][50], eid;
int tup[26 + 17][26 + 17];
void insert(std::string &s){
  int node = 0;
  for(int i = 0; i < s.size(); i++){
    const char ch = s[i] - 'a';
    if(tri[node][ch] == 0){
      tri[node][ch] = ++ eid;
    }
    node = tri[node][ch];
    
    for(int k = 0; k < 26; k++){
      if(i + 1 < s.size()){
        tup[k][s[i+1] - 'a'] += sum[tri[node][k]];
      }else{
        tup[k][26] += sum[tri[node][k]];
      }
    }
    sum[node]++;
  }
}

int query(std::string & s){
  int inv = 0;
  for(int i = 0; i < 26; i++){
    inv += tup[i][26];
    for(int j = 0; j < i; j++){
      inv += tup[s[i] - 'a'][s[j] - 'a'];
    }
  }
  return inv;
}

void solve(const std::size_t testcase){
  std::cin >> n >> q;
  for(int i = 1; i <= n; i++){
    std::string str;
    std::cin >> str;
    for(int j = 0; j < 26; j++){
      tup[j][str[0] - 'a'] += sum[tri[0][j]];
    }
    insert(str);
  }
  for(int t = 1; t <= q; t++){
    std::string str;
    std::cin >> str;
    std::cout << query(str) << "\n";
  }
}