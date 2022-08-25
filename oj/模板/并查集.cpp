#include <array>
const int maxn = 5000;
std::array<int, maxn> disjoint;
std::array<int, maxn> rank;

void disjoint_init() {
  for (int i = 0; i < disjoint.size(); i++) {
    disjoint[i] = i;
  }
}

int disjoint_find_root(int u) {
  while (disjoint[u] != u) {
    u = disjoint[u];
  }
  return u;
}

void disjoint_joint(int x, int y) {
  x = disjoint_find_root(x);
  y = disjoint_find_root(y);
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