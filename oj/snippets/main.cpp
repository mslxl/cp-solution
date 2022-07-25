#include <bits/stdc++.h>
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

template <typename T, typename... A> void read(T &value, A &..._t) {
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
  for (auto it = std::begin(a); it != std::end(a); ++it) {
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
#define IOS                                                                    \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(nullptr);                                                     \
    std::cout.tie(nullptr);                                                    \
  } while (0)
#define debug(...)                                                             \
  std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define IOS 114514
#define debug(...)                                                             \
  do {                                                                         \
  } while (0)
#endif

  using ll = long long;
using ul = unsigned long long;
#define rep(i, s, e) for (int i = s; i < e; i++)
#define fors(i, s, e) rep(i, s, e + 1)

// ----------------------------------------------------

int main() {
  IOS;
  std::string i;
  std::cin >> i;
  std::cout << i;
  debug("test", i);
  return 0;
}