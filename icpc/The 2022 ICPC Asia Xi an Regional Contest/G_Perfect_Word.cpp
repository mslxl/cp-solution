#include<bits/stdc++.h>

#define rep(NAME, MAX) for(int NAME = 0; NAME < MAX; i++)
#define rep1(NAME, MAX) for(int NAME = 1; NAME <= MAX; i++)
#define repv0(NAME, START) for(int NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for(int NAME = START; NAME >= 1; NAME--)

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

int main(){
  #ifdef ONLINE_JUDGE
	std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  #endif
  ll n;
  std::cin >> n;
  std::vector<std::string> words(n);
  ll maxlen = 0;
  rep(i, n) {
    std::cin >> words[i];
    maxlen = std::max(ll(words[i].size()), maxlen);
  }

  if(maxlen == 1){
    std::cout << 1;
    return 0;
  }

  std::sort(words.begin(), words.end(), [](const std::string &l, const std::string& r){
    return l.size() < r.size();
  });

  ll len = 1;
  for(auto iter = words.begin(); iter != words.end(); iter++){
    if(iter->size() - len > 1){
      // after is impossible
      words.erase(iter, words.end());
      break;
    }else{
      len = iter->size();
    }
  }

  std::set<std::string> exists;
  len = 0;
  rep(i, words.size()){
    if(words[i].size() == 1){
      exists.insert(words[i]);
      len = std::max(len, ll(words[i].size()));
    }else if(exists.count(words[i].substr(0, words[i].size()-1)) && exists.count(words[i].substr(1, words[i].size() - 1)) ){
      exists.insert(words[i]);
      len = std::max(len, ll(words[i].size()));
    }
  }
  std::cout << len;
	return 0;
}