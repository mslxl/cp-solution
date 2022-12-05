#include<bits/stdc++.h>

int N;
const int maxn = 5e3 + 17;

struct edge{
  int to;
  int next;
  int w;
}e[maxn];
int head[maxn], eid;

void add_edge(int u,int v, int w){
  eid++;
  e[eid].to = v;
  e[eid].w = w;
  e[eid].next = head[u];
  head[u] = eid;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cout.tie(nullptr);
  std::cin.tie(nullptr);

  std::cin >> N;
  for(int i = 1; i < N; i++){
    int u,v,w;
    std::cin >> u >> v >> w;
    add_edge(u, v, w);
  }
}