// 自分の得意な言語で
// Let's チャレンジ！！

// clang-format off
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); }
void solve(const std::size_t testcase);
#define rep(NAME, MAX) for(decltype(MAX) NAME = 0; NAME < MAX; NAME++)
#define rep1(NAME, MAX) for(decltype(MAX) NAME = 1; NAME <= MAX; NAME++)
#define repv0(NAME, START) for(decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for(decltype(START) NAME = START; NAME >= 1; NAME--)
int main() {
  std::size_t t = 1;
  // read(t);
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  rep1(i, t) solve(t);
  return 0;
}
// ------------ Minify with Regex "^\s*(?!#)(.*)\n" -> " " ------------
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#ifndef ONLINE_JUDGE
#define debug_do if(true)
#else
#define debug_do if(false)
#endif
#define debug(...) debug_do std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
// clang-format on

#define int ll
int n;
int a, b, c;

struct Sphere {
  int r;
  int x, y, z;
  bool operator<(const Sphere &rhs) const {
    if (x == rhs.x) {
      if (y == rhs.y) {
        if (z == rhs.z) {
          return r < rhs.r;
        }
        return z < rhs.z;
      }
      return y < rhs.y;
    }
    return x < rhs.x;
  }
};
std::ostream& operator<<(std::ostream& os, const Sphere& rhs) {
  return os << "(" << rhs.x << ", " << rhs.y<< ", " << rhs.z << ", r = " << rhs.r << ")";
}

bool is_valid(const std::vector<Sphere> &room) {
  for (int i = 0; i < room.size(); i++) {
    if (room[i].x - room[i].r < 0 || room[i].y - room[i].r < 0 ||
        room[i].z - room[i].r < 0 || room[i].x + room[i].r > a ||
        room[i].y + room[i].r > b || room[i].z + room[i].r > c) {
      return false;
    }
    for (int j = i+1; j < room.size(); j++) {
      double dis = std::sqrt(1.0 * std::pow((room[i].x - room[j].x), 2) +
                             std::pow((room[i].y - room[j].y), 2) +
                             std::pow((room[i].z - room[j].z), 2));
      debug(room[i], room[j], dis);
      if (dis < room[i].r + room[j].r) {
        return false;
      }
    }
  }
  return true;
}

int calc_remain(const std::vector<Sphere> &room) {
  double occupy = 0;
  for (const auto c : room) {
    occupy += 3.14159265 * std::pow(c.r, 3) * 4 / 3;
  }
  return std::round(a * b * c - occupy);
}

int ans = std::numeric_limits<int>::max();
void dfs(std::vector<Sphere> room, int idx) {
  if (idx >= room.size()) {
    return;
  }
  while (is_valid(room)) {
    debug(room);
    ans = std::min(ans, calc_remain(room));
    debug(ans);
    dfs(room, idx + 1);
    room[idx].r+=1;
  }
}

void solve(const std::size_t testcase) {
  read(n);
  read(b,a, c);
  std::vector<Sphere> pts(n);
  rep(i, n) {
    read(pts[i].x, pts[i].y, pts[i].z);
    pts[i].r = 0;
  }
  dfs(pts, 0);
  std::cout << ans;
}
