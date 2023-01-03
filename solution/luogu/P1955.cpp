// NOI_2015_程序自动分析
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#undef Local
#endif
#ifdef Local
#define tout \
  if (1)     \
  std::cerr
#else
#define tout \
  if (0)     \
  std::cerr
#endif
using ll = long long;
using ull = unsigned long long;
#define rep(i, s, e) for (int i = s; i < e; i++)
#define fors(i, s, e) rep(i, s, e + 1)

template <typename T>
void read(T& value) {
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

template <typename T, typename... A>
inline void read(T& value, A&... _t) {
  read(value);
  read(_t...);
}

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


disjoint_map eq;
void solve() {
  eq.clear();

  int n;
  read(n);
  std::vector<std::pair<int,int>> seq_ne;

  rep(_i, 0, n) {
    int op, a, b;
    read(a, b, op);
    if(op){
      eq.joint(a,b);
    }else{
      seq_ne.push_back({a,b});
    }
  }

  for(const auto& re : seq_ne){
    if(eq.is_joint(re.first, re.second)){
      std::cout << "NO" << std::endl;
      return;
    }
  }
  std::cout << "YES" << std::endl;

}

int main() {
#ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif

  int T;
  read(T);
  while (T--) {
    solve();
  }

  return 0;
}
