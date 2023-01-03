#include <array>
#include <bits/stdc++.h>

#define ONLINE_JUDGE

// 自分の得意な言語で
// Let's チャレンジ！！

using ll = long long;
using ul = unsigned long long;
using ld = long double;

// ------------ Minify with Regex "^\s*(?!#)(.*)\n" -> " " ------------
// clang-format off
template <class A, class B> std::ostream &operator<<(std::ostream &s, std::pair<A, B> const &a) { return s << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")"; } template <size_t n, typename... T> typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(std::ostream &, const std::tuple<T...> &) {} template <size_t n, typename... T> typename std::enable_if<(n < sizeof...(T))>::type print_tuple(std::ostream &os, const std::tuple<T...> &tup) { if (n != 0) os << ", "; os << std::get<n>(tup); print_tuple<n + 1>(os, tup); } template <typename... T> std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &tup) { os << "("; print_tuple<0>(os, tup); return os << ")"; } template <class T> std::ostream &print_collection(std::ostream &s, T const &a) { s << '['; for (auto it = std::begin(a); it != std::end(a); ++it) { s << *it; if (it != std::prev(end(a))) s << ", "; } return s << ']'; } template <class T, class U> std::ostream &operator<<(std::ostream &s, std::map<T, U> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::set<T> const &a) { return print_collection(s, a); } template <class T> std::ostream &operator<<(std::ostream &s, std::vector<T> const &a) { return print_collection(s, a); } void __debug_out() { std::cerr << std::endl; } template <typename T, class = typename std::enable_if<std::is_pointer<T>::value>::type> void __debug_out(T beg, T end) { std::cerr << '['; for (auto it = beg; it != end; it++) { std::cerr << *it; if (it != std::prev(end)) { std::cerr << ", "; } } std::cerr << ']' << std::endl; } template <typename H, typename... Tail> void __debug_out(H h, Tail... T) { std::cerr << " " << h; __debug_out(T...); }
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
#else
#define debug(...) do {} while (0)
#endif
// clang-format on

template <typename T>
inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x) {
  char c;
  T f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-')
      f = -1;
  x = (c & 15);
  while (isdigit(c = getchar()))
    x = (x << 1) + (x << 3) + (c & 15);
  x *= f;
}

template <typename T, typename... A> void read(T &value, A &..._t) {
  read(value);
  read(_t...);
}

#define rep(NAME, MAX) for (decltype(MAX) NAME = 0; NAME < MAX; NAME++)
#define rep1(NAME, MAX) for (decltype(MAX) NAME = 1; NAME <= MAX; NAME++)
#define repv0(NAME, START) for (decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for (decltype(START) NAME = START; NAME >= 1; NAME--)

// main function
template <std::size_t MAX_SIZE_EDGE, class TData = int> struct graph {
  struct node {
    int to{};
    TData data{};
    node(int t, TData d) : to(t), data(d) {}
  };
  std::array<std::list<node>, MAX_SIZE_EDGE> edges;

  graph() {}

  void add_edge(int u, int v, TData data = TData{}) {
    edges[u].emplace_back(v, data);
  }
  void add_biedge(int u, int v, TData data = TData{}) {
    add_edge(u, v, data), add_edge(v, u, data);
  }
  void clear() { edges.fill(std::list<node>()); }
  std::list<node> &from(std::size_t idx) noexcept { return (*this)[idx]; }
  std::list<node> &operator[](std::size_t idx) noexcept { return edges[idx]; }
};

const int maxn = 4e4 + 17;
const int maxk = 2e4 + 17;

graph<maxn> g;
int n;
int k;

int size[maxn];
int maxp[maxn];
int rt;
std::bitset<maxn> vis;
int sum;

// 这是来自 atcoder 的神秘力量 :)
namespace atcoder {

int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n))
    x++;
  return x;
}
template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
  segtree() : segtree(0) {}
  explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
  explicit segtree(const std::vector<S> &v) : _n(int(v.size())) {
    log = ceil_pow2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    for (int i = 0; i < _n; i++)
      d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    d[p] = x;
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }

  S get(int p) const {
    assert(0 <= p && p < _n);
    return d[p + size];
  }

  S prod(int l, int r) const {
    assert(0 <= l && l <= r && r <= _n);
    S sml = e(), smr = e();
    l += size;
    r += size;

    while (l < r) {
      if (l & 1)
        sml = op(sml, d[l++]);
      if (r & 1)
        smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }

  S all_prod() const { return d[1]; }

  template <bool (*f)(S)> int max_right(int l) const {
    return max_right(l, [](S x) { return f(x); });
  }
  template <class F> int max_right(int l, F f) const {
    assert(0 <= l && l <= _n);
    assert(f(e()));
    if (l == _n)
      return _n;
    l += size;
    S sm = e();
    do {
      while (l % 2 == 0)
        l >>= 1;
      if (!f(op(sm, d[l]))) {
        while (l < size) {
          l = (2 * l);
          if (f(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }

  template <bool (*f)(S)> int min_left(int r) const {
    return min_left(r, [](S x) { return f(x); });
  }
  template <class F> int min_left(int r, F f) const {
    assert(0 <= r && r <= _n);
    assert(f(e()));
    if (r == 0)
      return 0;
    r += size;
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2))
        r >>= 1;
      if (!f(op(d[r], sm))) {
        while (r < size) {
          r = (2 * r + 1);
          if (f(op(d[r], sm))) {
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

private:
  int _n, size, log;
  std::vector<S> d;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

} // namespace atcoder
using S = long long;
S op(S a, S b) { return a + b; }
S e() { return 0; }

atcoder::segtree<S, op, e> seg(20000 + 17);

void up_rt(int u, int fa) {
  size[u] = 1;
  for (auto &[v, w] : g[u]) {
    if (v == fa || vis[v])
      continue;
    up_rt(v, u);
    size[u] += size[v];

    maxp[u] = std::max(maxp[u], size[v]);
    debug(u, v, size[v], maxp[u]);
  }

  maxp[u] = std::max(maxp[u], sum - size[u]);
  if (maxp[u] < maxp[rt]) {
    rt = u;
    debug("set rt", rt, maxp[rt]);
  }
}

void up_size(int u, int fa) {
  size[u] = 1;
  for (auto &[v, w] : g[u]) {
    if (v == fa || vis[v])
      continue;
    up_size(v, u);
    size[u] += size[v];
  }
}
ll ans = 0;
ll dis[maxn];
ll disseq[maxn];
int seqcnt = 0;

void up_dis(int u, int fa) {
  disseq[seqcnt++] = dis[u];
  for (auto &[v, w] : g[u]) {
    if (v == fa || vis[v])
      continue;
    dis[v] = dis[u] + w;
    // disseq[seqcnt++] = dis[v];
    up_dis(v, u);
  }
}

void solve(int u) {
  std::queue<int> q;
  dis[u] = 0;
  for (auto &[v, w] : g[u]) {
    if (vis[v])
      continue;
    seqcnt = 0;
    dis[v] = w;
    up_dis(v, u);
    rep(j, seqcnt) {
      if (disseq[j] <= k) {
        ans += seg.prod(1, k - disseq[j] + 1) + 1;
      }
    }
    rep(j, seqcnt) {
      q.push(disseq[j]);
      seg.set(disseq[j], seg.get(disseq[j]) + 1);
    }
  }

  while (!q.empty()) {
    auto j = q.front();
    seg.set(j, seg.get(j) - 1);
    q.pop();
  }
}

void divide(int u) {
  vis[u] = true;
  solve(u);
  for (auto &[v, w] : g[u]) {
    if (vis[v])
      continue;

    sum = size[v];
    debug(sum);
    rt = 0;
    std::memset(maxp, 0, sizeof(maxp));
    maxp[0] = n;
    up_rt(v, 0);
    up_size(rt, 0);
    debug(rt);
    divide(rt);
  }
}

void solve(const std::size_t testcase) {
  // coding here
  read(n);
  rep(i, n - 1) {
    int u, v, w;
    read(u, v, w);
    g.add_biedge(u, v, w);
  }
  read(k);
  sum = n;
  maxp[0] = n;

  up_rt(1, 0);
  up_size(rt, 0);

  debug(rt);
  divide(rt);
  std::cout << ans;
}

#ifdef int
#undef int
#endif
int main() {
  std::size_t t = 1;
  // std::cin >> t;
  for (std::size_t i = 1; i <= t; i++) {
    solve(t);
  }

  return 0;
}
