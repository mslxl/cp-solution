// clang-format off
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
using pii = std::pair<int,int>; using pli = std::pair<ll, int>;using pll = std::pair<ll,ll>;
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
bool isPrime(int x){
  if(x <= 1) return false;
  for(int i = 2; i * i <= x; i++){
    if(x % i == 0){
      return false;
    }
  }
  return true;
}

int A, B;
std::unordered_map<int, int> happiness;
std::unordered_set<int> unhappiness;
std::unordered_set<int> dep_happiness;

int powsum(int V){
  int sum = 0;
  while(V != 0){
    sum += std::pow(V % 10, 2);
    V /= 10;
  }
  return sum;
}

int iter(int value, std::unordered_set<int>& r){
  if(value == 1) return 0;
  else if(happiness.count(value)) return happiness[value];
  else if(unhappiness.count(value)) return -1;
  else if(r.count(value)) return -1;
  r.insert(value);
  int dep = iter(powsum(value), r);
  if(dep == -1) unhappiness.insert(value);
  else happiness[value] = dep + 1;
  
  if(dep != -1){
    dep_happiness.insert(value);
    return dep + 1;
  }else{
    return -1;
  }
}

void solve(const std::size_t testcase){
  read(A, B);
  std::stack<pll> st;
  for(int i = B; i >= A; i--){
    std::unordered_set<int> r;
    if(happiness.count(i)) continue;
    int dep = iter(i, r);
    
    if(dep != -1){
      if(isPrime(i)) dep *= 2;
      st.push({i, dep});
    }
  }
  
  if(st.empty()){
    std::cout << "SAD";
  }else{
    while(!st.empty()){
      std::cout << st.top().first << " " << st.top().second << "\n";
      st.pop();
    } 
  }
 
}