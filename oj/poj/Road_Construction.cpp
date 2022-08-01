#include <cstring>
#include <iostream>
#include <set>
#include<stack>

int n, r;
const int maxr = 1e4;
const int maxn = 1e4 + 17;

struct {
  int next;
  int to;
} e[maxr * 2 + 17];

int heads[maxn], eid = 0;

int dfn[maxn], low[maxn], acc_time = 0;
std::stack<int> stack;

void add_edge(int u, int v) {
  eid++;
  auto &d = e[eid];
  d.to = v;
  d.next = heads[u];
  heads[u] = eid;
}
int degree[maxn];

void reinit() {
#define cls_arr(a) std::memset(a, 0, sizeof(a))
  cls_arr(e);
  cls_arr(heads);
  cls_arr(dfn);
  cls_arr(low);
  cls_arr(degree);
  eid = 0;
  acc_time = 0;
  while(!stack.empty()){
    stack.pop();
  }
#undef cls_arr
}

void tarjan(int u, int father) {
  dfn[u] = low[u] = ++acc_time;
  stack.push(u);
  for (int i = heads[u]; i; i = e[i].next) {
    const int v = e[i].to;
    if (v == father)
      continue;
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = std::min(low[u], low[v]);
    } else {
      low[u] = std::min(low[u], dfn[v]);
    }
  }
}

void solve(){
  tarjan(1, 0);
  for(int u = 1;u <=n;u++){
    for(int i = heads[u]; i; i=e[i].next){
      const int v = e[i].to;
      if(low[u]!=low[v]){
        degree[low[u]]++;
      }
    }
  }
  int leaf = 0;
  for(int i = 1; i<=n;i++){
    if(degree[i] == 1){
      leaf++;
    }
  }
  std::cout << (leaf+1)/2 << std::endl;
}

int main() {
  while (std::cin >> n >> r) {
    reinit();
    for (int i = 0; i < r; i++) {
      int u, v;
      std::cin >> u >> v;
      add_edge(u, v);
      add_edge(v, u);
    }
    solve();
  }
}