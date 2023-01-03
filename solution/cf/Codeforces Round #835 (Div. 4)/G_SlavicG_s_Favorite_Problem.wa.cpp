#include <bits/stdc++.h>

using ll = long long;
using ul = unsigned long long;
using ld = long double;

template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type read(T &value) {
  value = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    value = (value << 1) + (value << 3) + (ch ^ 48);
    ch = getchar();
  }
  value *= f;
}

template <typename T, typename... A> void read(T &value, A &..._t) {
  read(value);
  read(_t...);
}

template <class TData = int> struct graph {
  struct node {
    int to{};
    TData data{};
  };
  std::unordered_map<int, std::vector<node>> edges{};

  graph() {}
  void add_edge(int u, int v, TData data = TData{}) {
    edges[u].emplace_back(node{v, data});
  }
  void add_biedge(int u, int v, TData data = TData{}) {
    add_edge(u, v, data), add_edge(v, u, data);
  }
  void clear() { edges.clear(); }
  std::vector<node> &from(std::size_t idx) noexcept { return (*this)[idx]; }
  std::vector<node> &operator[](std::size_t idx) noexcept { return edges[idx]; }
};

#define int ll
void solve(const std::size_t testcase) {
  int n,a,b;
  read(n,a,b);

  graph<int> g;

  for(int i = 0 ; i < n-1; i++){
    int u,v,w;
    read(u,v,w);
    g.add_biedge(u,v,w);
  }

  std::map<int,int> areach, breach;
  std::map<int,int> ans;
  std::queue<std::pair<int,int>> seq;
  seq.push({a,0 });
  areach[a] = 0;
  while(!seq.empty()){
    auto [u,x] = seq.front();
    seq.pop();

    for(auto &n : g[u]){
      int v = n.to;
      if(areach.count(v) || v == b) continue;
      int w = x ^ n.data;
      areach[v] = w;
      seq.push({v, w});
      ans[w] = v;
    }
  }
  seq.push({b,0});
  while(!seq.empty()){
    auto [u,x] = seq.front();
    seq.pop();
    
    for(auto& n : g[u]){
      int v = n.to;
      if(breach. count(v)) continue;
      int w = x ^ n.data;
      if(ans.count(w)){
        std::cout << "YES\n";
        return;
      }
      breach[v] = w;
      seq.push({v, w});
    }
  }
 std::cout << "NO\n";
}

#undef int
int main() {

  int t;
  std::cin >> t;
  for (std::size_t i = 1; i <= t; i++) {
    solve(t);
  }

  return 0;
}