#include <bits/stdc++.h>
// 自分の得意な言語で
// Let's チャレンジ！！
// clang-format off
// ------------ Minify with Regex "^\s*(?!#)(.*)\n" -> " " ------------
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
#else
#define debug(...) do {} while (0)
#endif
// clang-format on

// clang-format off
using ll = long long; using ul = unsigned long long; using ld = long double;
template <typename T>
inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){
  char c;T f=1;
  while(!isdigit(c=getchar())) if(c=='-')f=-1;
  x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15);
  x*=f;
}
template <typename T, typename... A> void read(T &value, A &..._t) { read(value), read(_t...); }
#define rep(NAME, MAX) for(decltype(MAX) NAME = 0; NAME < MAX; NAME++)
#define replr(NAME, START, END) for(ll _sig = ((ll(END)-ll(START))/ std::abs(ll(END)-ll(START))), NAME = START; NAME != END; NAME+=_sig)
#define replrci(NAME, START, END) for(ll _sig = ((ll(END)-ll(START))/ std::abs(ll(END)-ll(START))), NAME = START+_sig; NAME-_sig != END; NAME+=_sig)
// clang-format on

// coding here
inline void solve(const std::size_t testcase) {
  std::string line;
  std::vector<std::string> lines;
  while (std::getline(std::cin, line)) {
    // debug(line);
    lines.push_back(line);
  }
  ll linenum = std::log10(lines.size()) + 1;
  std::string fmt = "%" + std::to_string(linenum) + "lld %s\n";
  debug(fmt, lines.size());

  rep(i,lines.size()){
    printf(fmt.data(), i+1, lines[i].data());
  }
}

#ifdef int
#undef int
#endif
int main() {
  std::size_t t = 1;
  // std::cin >> t;
  for (std::size_t i = 1; i <= t; i++)
    solve(t);
  return 0;
}
