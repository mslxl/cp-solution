#include <bits/stdc++.h>

// clang-format off
// ------------ Minify with Regex "^\s*(?!#)(.*)\n" -> " " ------------
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#ifndef ONLINE_JUDGE
#define debug_do if(true)
#else
#define debug_do if(false)
#endif
#define debug(...) debug_do std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
// clang-format on

const int maxalpha = 15;
int dis[maxalpha][maxalpha];
void init() {
  for (int i = 0; i < maxalpha; i++)
    for (int j = 0; j < maxalpha; j++)
      if (i == j)
        dis[i][j] = 0;
      else
        dis[i][j] = 0x3f3f3f;
}
void floyd() {
  for (int k = 0; k < maxalpha; k++)
    for (int i = 0; i < maxalpha; i++)
      for (int j = 0; j < maxalpha; j++)
        dis[i][j] = std::min(dis[i][k] + dis[k][j], dis[i][j]);
}

std::string pwd_init;
std::string pwd_final;

int main() {
  std::cin >> pwd_init;
  init();
  int n;
  std::cin >> n;
  for(int i = 0; i < n; i++){
    int a,b;
    std::cin >> a >> b;
    dis[a][b] = 1;
  }
  std::cin >> pwd_final;
  floyd();
  int ans = 0;
  for(int i = 0 ; i < pwd_init.size(); i++){
    int v = dis[pwd_init[i] - '0'][pwd_final[i] - '0'];
    if(v >= 0x3f3f3f){
      std::cout << -1;
      return 0;
    }
    debug(pwd_init[i]-'0',pwd_final[i] - '0', v);
    ans += v;
  }
  std::cout << ans;
  return 0;
}
