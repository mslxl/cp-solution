#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = s; i < e; i++)
#define fors(i, s, e) rep(i, s, e + 1)
const int maxn = 1e5 + 17;

template <typename T, T v>
struct DefaultValueImpl {
  T i;
  DefaultValueImpl() : i(v) {}
};

std::unordered_map<int, int> disjoint;
std::unordered_map<int, int> rank;
std::unordered_map<int, DefaultValueImpl<int, 1>> union_size;

int find(int x) {
  assert(x != 0);
  while (disjoint[x] != 0) {
    x = disjoint[x];
  }
  return x;
}

void union_set(int x, int y) {
  int root_x = find(x);
  int root_y = find(y);

  if (root_x == root_y) {
    union_size[root_x], union_size[root_y]; // caution! create default value
    return;
  }

  if (rank[root_x] > rank[root_y]) {
    disjoint[root_y] = root_x;

    union_size[root_x].i += union_size[root_y].i;
  } else if (rank[root_x] < rank[root_y]) {
    disjoint[root_x] = root_y;
    union_size[root_y].i += union_size[root_x].i;
  } else {
    disjoint[root_x] = root_y;
    rank[root_y]++;

    union_size[root_y].i += union_size[root_x].i;
  }
}

bool is_joint(int x, int y) {
  return find(x) == find(y);
}

void solve() {
  rank.clear();
  disjoint.clear();
  union_size.clear();
  int num;
  int x, y;
  std::cin >> num;
  rep(i, 0, num) {
    std::cin >> x >> y;
    union_set(x, y);
  }
  int result = 0;

  for (const auto& entry : union_size) {
    result = std::max(result, entry.second.i);
  }

  std::cout << result << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}