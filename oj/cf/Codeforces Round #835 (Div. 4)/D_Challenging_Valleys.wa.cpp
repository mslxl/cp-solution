#include<bits/stdc++.h>

using ll = long long;
using ul = unsigned long long;
using ld = long double;
// ------------ Minify with Regex "^\s*(?!#)(.*)\n" -> "$1 " ------------
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
#else
#define debug(...) do {} while (0)
#endif
// Codes Below
template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type read(T &value) {
  value = 0;
  char ch = getchar();
  bool flag = false;
  while (!std::isdigit(ch)) {
    if (ch == '-')
      flag = true;
    ch = getchar();
  }
  while (std::isdigit(ch)) {
    value = value * 10 + (ch - '0');
    ch = getchar();
  }
  if (flag)
    value *= -1;
}

template <typename T, typename... A> void read(T &value, A &..._t) {
  read(value);
  read(_t...);
}
bool judge(const std::vector<int> &diff, int start){
  int  i=start;
  bool inc = false, dec = false;
  bool needEq = false;
  if(i == 0 || diff[i] < 0) {
    if(i == 0) needEq = true;
    dec = true;
    i++;
    while(diff[i] < 0){
      i++;
    }
  }else{
    return false;
  }
  if(diff[i] == 0){
    needEq = false;
    while(diff[i] == 0){
      i++;
    }
  }
  if(diff[i] > 0 || i == diff.size()) {
    return !needEq;
  }
  return false; 
}
void solve(const std::size_t testcase){
  int n;
  read(n);
  std::vector<int> seq(n);
  std::vector<int> diff(n);
  for(int i = 0; i < n; i++) {
    read(seq[i]);
    if(i!=0){
      diff[i] = seq[i] - seq[i-1];
    }
  }
  if(n == 1) {
    std::cout << "YES\n";
    return;
  }
  for(int i = 0; i < n;i++){
    if(diff[i] < 0 || i == 0){
      if(judge(diff, i)){
        debug(i, diff);
        std::cout << "YES\n";
        return;
      }
    }
  }
  std::cout << "NO\n";
  return;
  
}

int main(){

	int t;
  std::cin >> t;
  for(std::size_t i = 1; i <= t; i++){
  	solve(t);
  }

	return 0;
}