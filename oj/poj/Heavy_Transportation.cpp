#include <cstring>
#include <queue>
#include <iostream>
#include <cassert>


#define INT32_MAX 2147483647
const int maxn = 1000;

struct _Edge {
  int next;
  int mess;
  int to;
} edges[maxn * maxn];

int heads[maxn], eid = 0;

void add_edge(int u,int v, int w){
  eid++;
  edges[eid].to = v;
  edges[eid].mess = w;
  edges[eid].next = heads[u];
  heads[u] = eid;
}

int n,m;
bool vis[maxn] = {false};
void clear() {
#define cls(x) std::memset(x, 0, sizeof(x))
  cls(edges);
  cls(heads);
  cls(vis);
  eid = 0;
}

struct Cmp{
  bool operator()(const std::pair<int,int> &lhs, const std::pair<int,int> &rhs){
    return lhs.second < rhs.second;
  }
};

int dj(int r){
  std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, Cmp> queue;
  queue.push(std::make_pair(r, INT32_MAX));
  while(!queue.empty()){
    std::pair<int,int> u = queue.top();
    queue.pop();
    vis[u.first] = true;
    if(u.first == n){
      return u.second;
    }
    for(int i = heads[u.first]; i; i=edges[i].next){
      if(vis[edges[i].to]) continue;
      queue.push(std::make_pair(edges[i].to, std::min(edges[i].mess, u.second)));
    }
  }
  assert(false);
  return 0;
}
void solve() { 
 clear(); 
 std::cin >> n >> m;
 for(int i = 0;i < m;i++ ){
  int u,v,w;
  std::cin >> u >> v >> w;
  add_edge(u,v,w);
  add_edge(v, u, w);
 }
 std::cout << dj(1) << "\n\n";

}

int main() {
  int T;
  std::cin >> T;
  for (int i = 1; i <= T; i++) {
    std::cout << "Scenario #" << i << ":\n";
    solve();
  }
  return 0;
}