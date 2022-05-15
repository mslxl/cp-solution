class disjoint_map {
 public:
  std::unordered_map<int, int> parent;
  std::unordered_map<int, int> ranking;

  int find(int n) {
    if (!parent.count(n))
      parent[n] = n;
    while (parent[n] != n) {
      n = parent[n];
    }
    return n;
  }

  bool is_joint(int x, int y) { return find(x) == find(y); }

  void joint(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x == root_y)
      return;
    if (ranking[root_x] > ranking[root_y]) {
      parent[root_y] = root_x;
    } else if (ranking[root_y] > ranking[root_x]) {
      parent[root_x] = root_y;
    } else {
      parent[root_x] = root_y;
      ranking[root_y]++;
    }
  }

  void clear() {
    parent.clear();
    ranking.clear();
  }
};
