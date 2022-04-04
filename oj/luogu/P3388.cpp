#include<bits/stdc++.h>

#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;

const int maxn = 2 * 1e5 + 15;
const int maxm = 1e6 + 15;

struct Node{
  int to = 0, next = 0;
} graph[maxm];

int head[maxn] = {0}, nid = 0;

void add_edge(int u, int v){
  nid++;
  graph[nid].to = v;
  graph[nid].next = head[u];
  head[u] = nid;
}

void add_biedge(int u, int v){ add_edge(u, v);
  add_edge(v, u);
}

int n, m;

std::set<int> cut_vertex;

int dfn[maxn]={0}, low[maxn] = {0};

void tarjan(int node,int father, int time = 1){
  if(node == 0 || dfn[node] != 0)
    return;

  low[node] = dfn[node] = time;
  const int u = node;

  test std::cout << "tarjan node " << node << std::endl;
  int counter = 0;
  for(int nid = head[node]; nid != 0; nid = graph[nid].next){
    const int v = graph[nid].to;


    if(v == father){
      continue;
    }

    if(dfn[v] == 0){
      tarjan(v, u, time + 1);
      low[node] = std::min(low[node], low[v]);

      if(low[v] >= dfn[u]){
        counter++;
        // is root?
        if(node != father || counter > 1){
          cut_vertex.insert(node);
          test std::cout << "node " << node << " is a cut-vertex" <<  std::endl;
        }
      }
    } else{
      low[node] = std::min(low[node], dfn[v]);
    }

  }

  test {
    std::cout << node <<" -> dfn=" << dfn[node] << " low=" << low[node] << std::endl;
  }
}

int main(){
  std::cin >> n >> m;

  for(int i = 0; i < m; i++){
    int x, y;
    std::cin >> x >> y;
    add_biedge(x,y);
  }


  for(int i = 1; i <= n; i++){
    if(dfn[i] == 0){
      tarjan(i, i);
    }
  }


  if(cut_vertex.empty()){
    std::cout << 0 << std::endl;
  }else{
    std::cout << cut_vertex.size() << std::endl;
    for(const auto& item : cut_vertex){
      std::cout << item << ' ';
    }
  }
  return 0;
}
