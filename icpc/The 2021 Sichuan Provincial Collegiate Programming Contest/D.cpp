// Problem: D. Rock Paper Scissors
// Contest: Codeforces - The 2021 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/103117/problem/D
// Memory Limit: 256 MB
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
   // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  read(t);
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
struct Card{
  char kd;
  int num;
  bool operator<(const Card& rhs) const {
    if(num == rhs.num){
      return kd < rhs.kd;
    };
    return num < rhs.num;
  }
};

std::vector<Card> b(3);
std::vector<Card> d(3);

int judge(){
  int bi = 0;
  int di = 0;
  int ans = 0;
  while(bi != 3 && di != 3){
      if((b[bi].kd == 'R' && d[di].kd == 'S') ||
        (b[bi].kd == 'P' && d[di].kd == 'R') ||
        (b[bi].kd == 'S' && d[di].kd == 'P')){
          int dec_num = std::min(b[bi].num, d[di].num);
          ans -= dec_num;
          b[bi].num -= dec_num;
          d[di].num -= dec_num;
        
          if(b[bi].num == 0) bi++;
          if(d[di].num == 0) di++;
          continue;
      }
      if((b[bi].kd == 'R' && d[di].kd == 'R')||
        (b[bi].kd == 'S' && d[di].kd == 'S')||
        (b[bi].kd == 'P' && d[di].kd == 'P')){
          int dec_num = std::min(b[bi].num, d[di].num);
          b[bi].num -= dec_num;
          d[di].num -= dec_num;
        
          if(b[bi].num == 0) bi++;
          if(d[di].num == 0) di++;
          continue;
      }
      if((b[bi].kd == 'R' && d[di].kd == 'P') ||
        (b[bi].kd == 'P' && d[di].kd == 'S') ||
        (b[bi].kd == 'S' && d[di].kd == 'R')){
          int dec_num = std::min(b[bi].num, d[di].num);
          ans += dec_num;
          b[bi].num -= dec_num;
          d[di].num -= dec_num;
        
          if(b[bi].num == 0) bi++;
          if(d[di].num == 0) di++;
          continue;
      }
  }
  debug(ans);
  return ans;
}

void solve(const std::size_t testcase){
    debug("---");
    read(b[0].num, b[1].num, b[2].num);
    b[0].kd = 'R';
    b[1].kd = 'P';
    b[2].kd = 'S';
    read(d[0].num, d[1].num, d[2].num);
    d[0].kd = 'R';
    d[1].kd = 'P';
    d[2].kd = 'S';
    std::sort(b.begin(), b.end());
    std::sort(d.begin(), d.end());
    int ans = std::numeric_limits<int>::min();
    do{
      do{
        auto rec_b = b;
        auto rec_d = d;
        ans = std::max(ans, judge());
        b = rec_b;
        d = rec_d;
      }while(std::next_permutation(d.begin(), d.end()));
    }while(std::next_permutation(b.begin(), b.end()));
    
    std::cout << ans << "\n";
}