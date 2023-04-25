#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
#define rep(i, s, e) for (int i = s; i < e; i++)
#define fors(i, s, e) rep(i, s, e + 1)

struct Edge {
  int from, to;
  int next;
} edges[10000];
int head[100 + 17], eid = 0;

int inde[100 + 17];

void add_edge(int u, int v) {
  eid++;
  edges[eid].to = v;
  edges[eid].from = u;
  edges[eid].next = head[u];
  head[u] = eid;
  inde[v]++;
}

void solve() {
  eid = 0;
  std::fill_n(inde, 100 + 17, 0);
  std::fill_n(head, 100 + 17, 0);

  int n, m;
  std::cin >> n >> m;
  rep(i, 0, m) {
    int u, v;
    std::cin >> u >> v;
    add_edge(u, v);
  }

  std::vector<int> array;
  std::priority_queue<int> seq;

  fors(i, 1, n) {
    if (inde[i] == 0)
      seq.push(i);
  }

  while (!seq.empty()) {
    int u = seq.top();
    seq.pop();
    array.push_back(u);
    for (int node_id = head[u]; node_id != 0; node_id = edges[node_id].next) {
      const int v = edges[node_id].to;
      inde[v]--;
      if (inde[v] <= 0) {
        seq.push(v);
      }
    }
  }
  if (array.size() == n) {
    fors(i, 1, n) { std::cout << (i == array[n / 2]); }
  } else {
    fors(i, 1, n) std::cout << 0;
  }
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
    if(T != 0){
      std::cout << " ";
    }
  }
  return 0;
}
