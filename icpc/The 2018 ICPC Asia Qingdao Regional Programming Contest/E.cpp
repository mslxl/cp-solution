// Problem: E. Plants vs. Zombies
// Contest: Codeforces - The 2018 ICPC Asia Qingdao Regional Programming Contest (The 1st Universal Cup, Stage 9: Qingdao)
// URL: https://codeforces.com/gym/104270/problem/E
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
  read(t);
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
int n, m;
std::vector<int> speed;

bool check(long long LIM) {
    long long step = 0;
    memset(B, 0, sizeof(long long) * (n + 3));
    for (int i = 1; i <= n; i++) {
        if (LIM > B[i]) {
            // 第 i 棵植物需要继续浇水
            // 在它和第 (i + 1) 棵植物之间反复移动
            long long t = LIM - B[i];
            t = (t + A[i] - 1) / A[i];
            step += t * 2 - 1;
            // 步数超出限制就即刻退出
            // 否则数据范围可能超出 long long
            if (step > m) return false;
            B[i + 1] += A[i + 1] * (t - 1);
        } else {
            // 第 i 棵植物不需要继续浇水
            // 直接路过，但步数还要算
            // 这里步数可能会超过限制
            // 但是只要右边没有其它需要浇水的植物，就不会返回 false
            step++;
        }
    }
    return true;
}

void solve(const std::size_t testcase){
  read(n, m);
  speed.resize(n + 1);
  int maxSpeed = 0;
  for(int i = 1; i <= n; i++) {
    read(speed[i]);
    maxSpeed = std::max(maxSpeed, speed[i]);
  }
  
  int L = 0, R = maxSpeed * m + 1;
  while(L <= R){
    int mid = L + (R - L) / 2;
    //int mid = (L + R) / 2;
    debug(L, mid, R);
    if(check(mid)){
      L = mid + 1;
    }else{
      R = mid - 1;
    }
  }
  std::cout << L-1 << "\n";
  debug("------");
}