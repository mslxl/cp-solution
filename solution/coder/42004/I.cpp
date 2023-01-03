#include <bits/stdc++.h>
#include <queue>
#include <utility>

int m, n, k;
const int maxm = 1e4 + 17;
const int maxn = 5e4 + 17;

int start, end;

struct edge {
  int to;
  int next;
  int w;
} e[maxn * 2 + 1];
int eid, head[maxm];

/* struct redge {
  int to;
  int next;
  int w;
} re[maxn * 2];
int reid, rhead[maxm];

void add_rev(int v, int u, int w) {
  reid++;
  re[reid].to = v;
  re[reid].next = rhead[u];
  re[reid].w = w;
  rhead[u] = reid;
} */

void add(int u, int v,int w) {
  eid++;
  e[eid].to = v;
  e[eid].next = head[u];
  e[eid].w = w;
  head[u] = eid;
  //add_rev(u, v, w);
}

void addbi(int u,int v, int w){
  add(u,v,w);
  add(v,u,w);
}

std::vector<bool> bvis;
std::set<int> real_start;
bool bfs(){
  std::queue<std::pair<int,int>> seq;
  bvis.resize(m);
  seq.push(std::make_pair(start, 0));
  bvis[start] = true;
  while(!seq.empty()){
    const auto data = seq.front();
    seq.pop();
    const int u = data.first, depth = data.second;
    if(depth == k){
      real_start.insert(u);
      continue;
    }
    for(int i = head[u]; i; i = e[i].next){
        const int v = e[i].to;
        if(bvis[v]) continue;
        bvis[v] = true;
        seq.push(std::make_pair(v, depth + 1));

        if(v == end){ // 用综测分就到了
            return true;
        }
    }
  }
  return false;
}

std::vector<bool> dvis;

int dj(){
  dvis.resize(m);
  using pr = std::pair<int,int>;
  std::priority_queue<pr, std::vector<pr>, std::greater<pr>> seq;

  seq.push(std::make_pair(0, end));
  while(!seq.empty()){
    const auto data = seq.top();
    seq.pop();
    const int w = data.first, u = data.second;
      if(real_start.count(u)){
        return w;
      }

    if(dvis[u]) continue;
    dvis[u] = true;
    
    for(int i = head[u]; i; i = e[i].next){
      const int v=  e[i].to;
      if(dvis[v]) continue;
      const int nw = e[i].w + w;

      
      seq.push(std::make_pair(nw, v));
    }

  }
  return -1;
}


int main() {
  std::cin >> m >> n >> k;
  std::cin >> start >> end;
  for(int i = 0; i < n; i++){
    int u,v,w;
    std::cin >> u >> v >> w;
    addbi(u, v, w);
  }

  if(bfs()){
    std::cout << 0;
    return 0;
  }

  for(auto start: real_start) {
    std::cerr << start << " ";
  }
  std::cerr << std::endl;

  std::cout << dj();
  return 0;
}