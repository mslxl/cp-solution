#include<bits/stdc++.h>
#include <memory>
#include <queue>

using ll = long long;
using ul = unsigned long long;
using ld = long double;
const int maxn = 100 + 17;
const int maxm = (500 + 17) * 2 + 1;

struct edge{
  int to;
  int w,v;
  int next;
}e[maxm];

int head[maxn], eid = 0;
void add_edge(int u,int v, int w, int vv){
  eid++;
  e[eid].to = v;
  e[eid].w = w;
  e[eid].v = vv;
  e[eid].next = head[u];
  head[u] = eid;
}

int n,m,c;

struct rou{
  int pt;
  int maxV;
  int remian;

  bool operator<(const rou&rhs) const {
    return maxV < rhs.maxV;
  }
};

bool vis[maxn];


int main(){
  std::cin >> n >> m >> c;
  for(int i = 0; i < m; i++){
    int x,y,w, v;
    std::cin >> x>>y >> w >> v;
    add_edge(x, y, w, v);
    add_edge(y, x, w, v);
  }

  std::priority_queue<rou> que;
  que.push(rou{1, 0x3f3f3f3f, c});
  while(!que.empty()){
    rou p = que.top();
    que.pop();

    if(p.pt == n){
      std::cout << p.maxV;
      return 0;
    }

    if(vis[p.pt]) continue;
    vis[p.pt] = true;
    for(int i = head[p.pt]; i; i = e[i].next){
      rou r{
        e[i].to,
        std::min(e[i].w, p.maxV),
        p.remian - e[i].v
      };
      if(r.remian < 0) continue;
      if(vis[e[i].to]) continue;
      que.push(r);
    }
  }
	return 0;
}