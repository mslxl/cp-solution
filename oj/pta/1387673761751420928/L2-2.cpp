#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = s; i < e; i++)

const int maxn = 1e4 + 17;
typedef long long ll;
struct Edge{
  int next, to;
};
std::vector<Edge> nodes;
int head[maxn] = {0}, eid = 0;

void add_edge(int u, int v){
  Edge e;
  e.to = v;
  e.next= head[u];
  nodes.push_back(e);
  head[u]  = nodes.size() - 1;
}

struct Point{
  int id, indegree = 0;
  bool operator < (const Point& rhs) const {
    return this->indegree < rhs.indegree;
  }
} points[maxn];

std::vector<std::vector<int>>  routes;
void dfs(int node, const std::vector<int>& pass){
  test {
    for(const auto& item: pass){
      std::cout << "->" << item;
    }
    std::cout << std::endl;
  }

  if(head[node] == -1){
    routes.push_back(pass);
    return;
  }
  for(int node_id = head[node]; node_id != -1; node_id = nodes[node_id].next){
    const int v = nodes[node_id].to;
    std::vector<int> route(pass);
    route.push_back(v);
    dfs(v, route);
  }
}

int n;

int main(){
  std::memset(head, -1, sizeof(head));
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  nodes.push_back(Edge());

  std::cin >> n;
  rep(u, 0, n){
    points[u].id = u;
    int m;
    std::cin >> m;
    rep(j, 0, m){
      int v;
      std::cin >> v;
      add_edge(u, v);
      points[v].indegree++;
    }
  }
  std::sort(points, points + n);
  test std::cout << "Start from " << points[0].id << std::endl;
  std::vector<int> initial;
  initial.push_back(points[0].id);
  dfs(0, initial);
  std::sort(routes.begin(), routes.end(), [](const std::vector<int>& lhs, const std::vector<int>& rhs)->bool{
      if(lhs.size() != rhs.size()) return lhs.size() > rhs.size();
      else return lhs < rhs;
  });
  std::cout << routes[0].size() << std::endl;
  std::cout << routes[0][0];
  rep(i, 1, routes[0].size()){
    std::cout << ' ' << routes[0][i];
  }
  return 0;
}
