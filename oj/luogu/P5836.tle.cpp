#include <bits/stdc++.h>
#ifdef Lo
#define test if (1)
#else
#define test if (0)
#endif

const int maxn = 1e5 + 13;
typedef long long ll;

struct edge {
  int next, to;
} node[maxn];
int eid = 0;
int head[maxn] = {0};

void add_edge(int u, int v) {
  eid++;
  node[eid].to = v;
  node[eid].next = head[u];
  head[u] = eid;
}
void add_biedge(int u, int v) {
  add_edge(u, v);
  add_edge(v, u);
}

int N, M;
std::string cow;

struct Footprint {
  int location;
  std::set<int> vis;
  std::set<char> cow;
};

void solve(int from, int to, char like) {
  //test std::cout << from << " -> " << to << " cos " << like << std::endl;
  std::queue<Footprint> route;
  auto fp = Footprint{from};
  fp.cow.insert(cow[from]);
  fp.vis.insert(from);
  route.push(fp);

  while (!route.empty()) {
    fp = route.front();
    route.pop();

    const int u = fp.location;
    if(u == to){
      if(fp.cow.count(like)){
        std::cout << 1;
        return;
      }else{
        std::cout << 0;
      }

      return;
    }

    for (int node_id = head[u]; node_id != 0; node_id = node[node_id].next) {
      const int v = node[node_id].to;
      // test std::cout << "vis " << v << std::endl;
      if(fp.vis.count(v)) {
        // test std::cout << "skip" << std::endl;
        continue;
      }
      auto nfp = fp.cow;
      auto vis = fp.vis;
      nfp.insert(cow[v]);
      vis.insert(v);
      route.push(Footprint{v, vis, nfp});
    }
  }
  std::cout << 0;
}

int main() {
  test {}
  else {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

  std::cin >> N >> M;
  std::cin >> cow;
  cow = std::string("C") + cow;

  for (int i = 0; i < N - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    add_biedge(u, v);
  }

  for (int i = 0; i < M; i++) {
    int u, v;
    char c;
    std::cin >> u >> v >> c;
    solve(u, v, c);
  }
  return 0;
}
