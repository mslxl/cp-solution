#include <bits/stdc++.h>
#include <tuple>
using ll = long long;
using ul = unsigned long long;
using ld = long double;

// ------------ Minify with Regex "^\s*(?!#)(.*)\n" -> " " ------------
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
#ifndef ONLINE_JUDGE
#define debug(...)                                                             \
  std::cerr << "[" << #__VA_ARGS__ << "]:", __debug_out(__VA_ARGS__)
#else
#define debug(...)                                                             \
  do {                                                                         \
  } while (0)
#endif
// Codes Below

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

namespace lazyseg {
int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n))
    x++;
  return x;
}
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
public:
  lazy_segtree() : lazy_segtree(0) {}
  explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
  explicit lazy_segtree(const std::vector<S> &v) : _n(int(v.size())) {
    log = ceil_pow2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    lz = std::vector<F>(size, id());
    for (int i = 0; i < _n; i++)
      d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    d[p] = x;
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }

  S get(int p) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    return d[p];
  }

  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r)
      return e();

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l)
        push(l >> i);
      if (((r >> i) << i) != r)
        push((r - 1) >> i);
    }

    S sml = e(), smr = e();
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

  S all_prod() { return d[1]; }

  void apply(int p, F f) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--)
      push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= log; i++)
      update(p >> i);
  }
  void apply(int l, int r, F f) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r)
      return;

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l)
        push(l >> i);
      if (((r >> i) << i) != r)
        push((r - 1) >> i);
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1)
          all_apply(l++, f);
        if (r & 1)
          all_apply(--r, f);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l)
        update(l >> i);
      if (((r >> i) << i) != r)
        update((r - 1) >> i);
    }
  }

  template <bool (*g)(S)> int max_right(int l) {
    return max_right(l, [](S x) { return g(x); });
  }
  template <class G> int max_right(int l, G g) {
    assert(0 <= l && l <= _n);
    assert(g(e()));
    if (l == _n)
      return _n;
    l += size;
    for (int i = log; i >= 1; i--)
      push(l >> i);
    S sm = e();
    do {
      while (l % 2 == 0)
        l >>= 1;
      if (!g(op(sm, d[l]))) {
        while (l < size) {
          push(l);
          l = (2 * l);
          if (g(op(sm, d[l]))) {
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

  template <bool (*g)(S)> int min_left(int r) {
    return min_left(r, [](S x) { return g(x); });
  }
  template <class G> int min_left(int r, G g) {
    assert(0 <= r && r <= _n);
    assert(g(e()));
    if (r == 0)
      return 0;
    r += size;
    for (int i = log; i >= 1; i--)
      push((r - 1) >> i);
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2))
        r >>= 1;
      if (!g(op(d[r], sm))) {
        while (r < size) {
          push(r);
          r = (2 * r + 1);
          if (g(op(d[r], sm))) {
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
  std::vector<F> lz;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, F f) {
    d[k] = mapping(f, d[k]);
    if (k < size)
      lz[k] = composition(f, lz[k]);
  }
  void push(int k) {
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = id();
  }
};
} // namespace lazyseg

#define rep(NAME, MAX) for (decltype(MAX) NAME = 0; NAME < MAX; i++)
#define rep1(NAME, MAX) for (decltype(MAX) NAME = 1; NAME <= MAX; i++)
#define repv0(NAME, START) for (decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for (decltype(START) NAME = START; NAME >= 1; NAME--)

#define int ll
const int MAXN = 1e5 + 17, MAXM = 1e5 + 17;
int N, M, R, P;

int nodew[MAXN];
graph<MAXN> g;

struct S {
  ll sum, len;
};
S op(S l, S r) { return S{l.sum + r.sum, l.len + r.len}; }
S e() { return S{0, 0}; }
using F = ll;

S mapping(F f, S x) { return {x.sum + f * x.len, x.len}; }

F composition(F l, F r) { return l + r; }

F id() { return 0; }

int node_size[MAXN];
int dfn[MAXN];
int depth[MAXN];
int father[MAXN];
int heavy_son[MAXN];
int top[MAXN];
int tim = 0;
std::vector<S> node_order_indfs{S{0, 1}};

void dfs1(int u, int fa) {
  node_size[u] = 1;
  depth[u] = depth[fa] + 1;
  father[u] = fa;

  int maxsize = -1;
  for (auto n : g[u]) {
    if (n.to == fa)
      continue;
    dfs1(n.to, u);
    node_size[u] += node_size[n.to];
    if (node_size[n.to] > maxsize) {
      maxsize = node_size[n.to];
      heavy_son[u] = n.to;
    }
  }
}

void dfs2(int u, int ttop) {
  dfn[u] = ++tim;
  top[u] = ttop;
  debug("11");
  node_order_indfs.push_back({nodew[u], 1});
  debug("22");
  if (heavy_son[u] == 0)
    return;
  dfs2(heavy_son[u], ttop);

  for (auto &[v, w] : g[u]) {
    if (v == heavy_son[u])
      continue;
    if (v == father[u])
      continue;
    dfs2(v, v);
  }
}

std::ostream &operator<<(std::ostream &os, const S &rhs) {
  return os << "{" << rhs.sum << ", " << rhs.len << "}";
}

void solve(const std::size_t testcase) {
  read(N, M, R, P);
  rep1(i, N) read(nodew[i]);
  rep(i, N - 1) {
    int x, y;
    read(x, y);
    g.add_biedge(x, y);
  }
  debug(R);
  debug("dfs");
  dfs1(R, 0);
  debug("dfs");
  dfs2(R, R);
  debug(node_order_indfs);
  debug("seg");
  lazyseg::lazy_segtree<S, op, e, F, mapping, composition, id> seg_tree(
      node_order_indfs);

  rep(i, M) {
    int op;
    read(op);
    if (op == 1) {
      int x, y, z;
      read(x, y, z);

      z %= P;
      while (top[x] != top[y]) {
        if (depth[top[x]] < depth[top[y]]) {
          std::swap(x, y);
        }
        debug(dfn[top[x]], dfn[x]);
        seg_tree.apply(dfn[top[x]], dfn[x] + 1, z);
        x = father[top[x]];

        if (x == 0) {
          x = R;
          break;
        }
      }
      if (depth[x] > depth[y]) {
        std::swap(x, y);
      }
      debug(dfn[x], dfn[y]);
      seg_tree.apply(dfn[x], dfn[y] + 1, z);
    } else if (op == 2) {
      int x, y;
      read(x, y);
      int ret = 0;
      while (top[x] != top[y]) {
        if (depth[top[x]] < depth[top[y]])
          std::swap(x, y);
        ret += seg_tree.prod(dfn[top[x]], dfn[x] + 1).sum;
        ret %= P;
        x = father[top[x]];
        if (x == 0) {
          x = R;
          break;
        }
      }
      if (depth[x] > depth[y]) {
        std::swap(x, y);
      }
      ret += seg_tree.prod(dfn[x], dfn[y] + 1).sum;
      std::cout << ret % P << "\n";

    } else if (op == 3) {
      int x, z;
      read(x, z);
      debug(dfn[x], dfn[x] + node_size[x], z);
      seg_tree.apply(dfn[x], dfn[x] + node_size[x], z);
    } else if (op == 4) {
      int root;
      read(root);
      debug("op4", dfn[root], dfn[root] + node_size[root]);
      std::cout << seg_tree.prod(dfn[root], dfn[root] + node_size[root]).sum % P
                << "\n";
    }
  }
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
