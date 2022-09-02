#include <array>
#include <unordered_map>

namespace ojlib {
template <std::size_t Size = 5000, typename T = int,
          typename Container = std::array<T, Size>>
struct Disjoint {
  Container disjoint;
  Container rank;
  Disjoint() {
    for (int i = 0; i < Size; i++)
      disjoint[i] = i;
  }
  T find_root(T u) {
    while (disjoint[u] != u)
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
} // namespace ojlib
