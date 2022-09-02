#include <bits/stdc++.h>
#include <climits>
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
void __debug_out() { std::cerr << std::endl; }
template <typename T,
          class = typename std::enable_if<std::is_pointer<T>::value>::type>
void __debug_out(T beg, T end) {
  std::cerr << '[';
  for (auto it = beg; it != end; it++) {
    std::cerr << *it;
    if (it != std::prev(end)) {
      std::cerr << ", ";
    }
  }
  std::cerr << ']' << std::endl;
}

template <typename H, typename... Tail> void __debug_out(H h, Tail... T) {

  std::cerr << " " << h;
  __debug_out(T...);
}

#ifdef Local
#define IOS                                                                    \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(nullptr);                                                     \
    std::cout.tie(nullptr);                                                    \
  } while (0)
#define debug(...)                                                             \
  std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
#else
#define IOS 114514
#define debug(...)                                                             \
  do {                                                                         \
  } while (0)
#endif
// --------------------------------------
constexpr int maxn = 1e5 + 17;
constexpr int maxw = INT_MAX;

struct Edge {
  int to, w;
  int next;
} e[2 * maxn + 1];
int head[maxn], eid = 0;
void add_edge(int u, int v, int w) {
  eid++;
  auto &i = e[eid];
  i.w = w;
  i.to = v;
  i.next = head[u];
  head[u] = eid;
}
int n;
int dx[maxn];

void dfs(int u, int fa) {
  for (int i = head[u]; i; i = e[i].next) {
    const int v = e[i].to, w = e[i].w;
    if (v == fa)
      continue;
    dx[v] = dx[u] ^ w;
    dfs(v, u);
  }
}

namespace trie {
constexpr int max_bit_len = 31;
constexpr int max_depth = max_bit_len * maxn;

std::array<std::array<int,2>, max_depth> trie;
int total_depth = 0;

void insert(int num) {
  int depth = 0;
  for (int i = max_bit_len; i >= 0; i--) {
    bool b = num & (1 << i);
    if (trie[depth][b] == 0) {
      trie[depth][b] = ++total_depth;
    }
    depth = trie[depth][b];
  }
}
int find(int num) {
  int depth = 0, result = 0;
  for (int i = max_bit_len; i >= 0; i--) {
    bool b = num & (1 << i);

    if (trie[depth][b ^ 1]) {
      result += 1 << i;
      depth = trie[depth][b ^ 1];
    } else {
      depth = trie[depth][b];
    }
  }
  return result;
}
}; // namespace trie


int main() {
  IOS;

  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    add_edge(u, v, w);
    add_edge(v, u, w);
  }
  dfs(1,1);

  for(int i = 1; i <= n; i++){
    trie::insert(dx[i]);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    ans = std::max(ans, trie::find(dx[i]));
  }
  std::cout << ans;
  return 0;
}