#include<bits/stdc++.h>

using ll = long long;
using ul = unsigned long long;
using ld = long double;

template <class TData = int> struct graph {
  struct node {
    int to{};
    TData data{};
  };
  std::unordered_map<int, std::vector<node>> edges{};

  graph(){}
  void add_edge(int u, int v, TData data = TData{}) {edges[u].emplace_back(node{v,data});}
  void add_biedge(int u, int v, TData data = TData{}) {add_edge(u, v, data),add_edge(v, u, data);}
  void clear() {edges.clear();}
  std::vector<node>& from(std::size_t idx) noexcept{return (*this)[idx];}
  std::vector<node>& operator[](std::size_t idx) noexcept{return edges[idx];}
};
template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type read(T &value) {
  value = 0;
  char ch = getchar();
  bool flag = false;
  while (!std::isdigit(ch)) {
    if (ch == '-')
      flag = true;
    ch = getchar();
  }
  while (std::isdigit(ch)) {
    value = value * 10 + (ch - '0');
    ch = getchar();
  }
  if (flag)
    value *= -1;
}

template <typename T, typename... A> void read(T &value, A &..._t) {
  read(value);
  read(_t...);
}
void solve(const std::size_t testcase){
  int n,a,b;
  read(n,a,b);
  graph<int> g;
  for(int i = 0; i < n; i++){
    int u,v,w;
    read(u,v,w);
    g.add_biedge(u, v,w);
  }
}

int main(){

	int t;
  std::cin >> t;
  for(std::size_t i = 1; i <= t; i++){
  	solve(t);
  }

	return 0;
}