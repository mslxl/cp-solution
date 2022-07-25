#include <bits/stdc++.h>
#include <iterator>
#include <ostream>
#include <type_traits>
#ifdef ONLINE_JUDGE
#undef Local
#endif

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

template <typename T, typename... A> inline void read(T &value, A &..._t) {
  read(value);
  read(_t...);
}
template <class A, class B>
std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) {
  return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")";
}

template <size_t n, typename... T>
typename std::enable_if<(n >= sizeof...(T))>::type
print_tuple(std::ostream &, const std::tuple<T...> &) {}

template <size_t n, typename... T>
typename std::enable_if<(n < sizeof...(T))>::type
print_tuple(std::ostream &os, const std::tuple<T...> &tup) {
  if (n != 0)
    os << ", ";
  os << std::get<n>(tup);
  print_tuple<n + 1>(os, tup);
}

template <typename... T>
std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) {
  os << "(";
  print_tuple<0>(os, tup);
  return os << ")";
}

template <class T> std::ostream &print_collection(std::ostream &s, T const &a) {
  s << '[';
  for (auto it = begin(a); it != end(a); ++it) {
    s << *it;
    if (it != std::prev(end(a)))
      s << ", ";
  }
  return s << ']';
}
template <class T, class U>
std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) {
  return print_collection(s, a);
}
template <class T>
std::ostream &operator<<(std::ostream &s, std::set<T> const &a) {
  return print_collection(s, a);
}
template <class T>
std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) {
  return print_collection(s, a);
}
void debug_out() { std::cerr << std::endl; }

template <typename T,
          class = typename std::enable_if<std::is_pointer<T>::value>::type>
void debug_out(T beg, T end) {
  std::cerr << '[';
  for (auto it = beg; it != end; it++) {
    std::cerr << *it;
    if (it != std::prev(end)) {
      std::cerr << ", ";
    }
  }
  std::cerr << ']' << std::endl;
}

template <typename H, typename... Tail>
void debug_out(H h, Tail... T) {

  std::cerr << " " << h;
  debug_out(T...);
}

#ifdef Local
#define debug(...)                                                             \
  std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)                                                             \
  do {                                                                         \
  } while (0)
#endif

using ll = long long;
using ul = unsigned long long;
#define rep(i, s, e) for (int i = s; i < e; i++)
#define fors(i, s, e) rep(i, s, e + 1)

const int maxn = 2 * 1e5 + 17;

struct Station {
  ll id;
  ll idx;
  bool operator<(const Station &rhs) const {
    if (this->id == rhs.id)
      return this->idx < rhs.idx;
    else
      return this->id < rhs.id;
  }
} s[maxn];

std::ostream &operator<<(std::ostream &os, const Station &s) {
  return os << "(" << s.id << ", " << s.idx << ")";
}

void solve() {
  ll l, q;
  std::cin >> l >> q;

  for (std::size_t i = 0; i < l; i++) {
    std::cin >> s[i].id;
    s[i].idx = i;
  }
  std::sort(s, s + l);
  debug(s, s + l);

  while (q--) {
    ll from, to;
    std::cin >> from >> to;

    auto cmp = [](const Station &lhs, const Station &rhs) -> bool const {
      return lhs.id < rhs.id;
    };
    auto fsf = (std::lower_bound(s, s + l, Station{from, 0}, cmp));
    auto tsl = (std::upper_bound(s, s + l, Station{to, 0}, cmp));
    debug(from, to);
    debug("search",*fsf, *(tsl-1));

    if (fsf != s + l && (tsl - 1)->id == to && fsf->idx < (tsl - 1)->idx) {
        debug("yes");
      std::cout << "YES\n";
    } else {
        debug("no");
      std::cout << "NO\n";
    }
  }
}

int main() {
#ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}