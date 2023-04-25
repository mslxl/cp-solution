#include<bits/stdc++.h>
#include <type_traits>

// ------------ Minify with Regex "^\s*(?!#)(.*)\n" -> "$1 " ------------
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
#else
#define debug(...) do {} while (0)
#endif
// Codes Below

using ll = long long;
using ul = unsigned long long;
using ld = long double;

template <typename T>
inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){
	char c;T f=1;
	while(!isdigit(c=getchar())) if(c=='-')f=-1;
	x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15);
	x*=f;
}

template <typename T, typename... A> void read(T &value, A &..._t) {
  read(value);
  read(_t...);
}

#define rep(NAME, MAX) for(decltype(MAX) NAME = 0; NAME < MAX; i++)
#define rep1(NAME, MAX) for(decltype(MAX) NAME = 1; NAME <= MAX; i++)
#define repv0(NAME, START) for(decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for(decltype(START) NAME = START; NAME >= 1; NAME--)

template <std::size_t Size = 5000, typename T = int, typename Container = std::conditional<Size==0, std::unordered_map<T, T>,  std::array<T, Size>>>
struct Disjoint {
  Container disjoint;
  Container rank;
  Disjoint() {
    for (int i = 0; i < Size; i++)
      disjoint[i] = i;
  }



  template<std::size_t _Size = Size>
  T find_root(T u, typename std::enable_if<_Size != 0>::type* =nullptr) {
    while (disjoint[u] != u)
      u = disjoint[u];
    return u;
  }

  template<std::size_t _Size = Size>
  T find_root(T u, typename std::enable_if<_Size == 0>::type* =nullptr) {
    while (disjoint.count(u))
      u = disjoint[u];
    return u;
  }


  bool is_joint(T u, T v) { return find_root(u) == find_root(v); }

  void joint(T x, T y) {
    x = find_root(x);
    y = find_root(y);
    if (x == y)
      return;
    if (rank[x] > rank[y]) {
      disjoint[y] = x;
    } else if (rank[y] > rank[x]) {
      disjoint[x] = y;
    } else {
      disjoint[x] = y;
      rank[y]++;
    }
  }
};


void solve(const std::size_t testcase){
  Disjoint<0, int, std::unordered_map<int, int>> disjoint;
  int t;
  read(t);
  std::vector<std::pair<int,int>> neq;

  rep(i, t){
    int op, x1,x2;
    read(x1, x2,op);
    if(op == 1){
      disjoint.joint(x1, x2);
    }else{
      neq.emplace_back(x1,x2);
    }
  }

  rep(i, neq.size()){
    auto ne = neq[i];
    if(disjoint.is_joint(ne.first, ne.second)) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
}

#ifdef int
#undef int
#endif
int main(){
	std::size_t t = 1;
  std::cin >> t;
  for(std::size_t i = 1; i <= t; i++){
  	solve(t);
  }

	return 0;
}
