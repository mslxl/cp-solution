#include<bits/stdc++.h>
#include <iostream>
#ifdef Lo
#define test if(1)
#else
#define test if(0)
#endif

const int maxn = 5e5 + 100;
struct Node{
  int value;
  int parent;
  std::vector<int> child;
  int depth;

  bool operator <(const Node&rhs) const {
    assert(this->value != rhs.value);
    return this->depth < rhs.depth;
  }
}nodes[maxn];

int N, M, S;

int st[maxn][19];
void build_st(){
  for(int i = 1; i <= N; i++){
    st[i][0] = nodes[i].parent;
  }
  for(int j = 1; j <= 18; j++){
    for(int i = 1; i <= N; i++){
      st[i][j] = st[st[i][j-1]][j-1];
    }
  }
}

int jump_up(int node, int depth){
  if(depth == 0) return node;
  test std::cout << "node "<< node << " will jump up " << depth << std::endl;
  assert(depth > 0);
  while(depth > 0){
    int j = 0;
    while(1 << (j+1) < depth){
      j++;
    }
    test std::cout << "try j = " << j << ", depth = " << depth << std::endl;
    node = st[node][j];
    depth -= (1 << j);
  }
  test std::cout << "reach target node: " << node << std::endl << std::endl;
  return node;
}

void append_depth_info(int root, int depth){
  nodes[root].depth = depth;
  for(auto &n : nodes[root].child){
    append_depth_info(n, depth+1);
  }
}

int lca(int a,int b){
  test std::cout << "ask lca of " << a << " and " << b << std::endl;
  auto low = std::max(nodes[a], nodes[b]);
  auto high = std::min(nodes[a], nodes[b]);
  test std::cout << "low.depth=" << low.depth << ", high.depth=" << high.depth << std::endl;
  if(low.depth != high.depth){
    low = nodes[jump_up(low.value, low.depth - high.depth)];
  }
  test std::cout << "align depth, " <<  low.value << ".depth=" << low.depth
    << " " << high.value <<".depth=" << high.depth << std::endl;

  int node;
  int upward_len = low.depth - 1;
  while((node = jump_up(low.value, upward_len)) == jump_up(high.value, upward_len)){
    upward_len--;
  }
  return nodes[node].parent;
}

int main(){
  std::cin>> N >> M >> S;

  for(int i = 1; i < N; i++){
    int x,y;
    std::cin >> x >> y;
    test std::cout << x << " have parent node " << y << std::endl;
    nodes[x].parent = y;
    nodes[x].value = x;
    nodes[y].child.push_back(x);
  }
  append_depth_info(S, 1);
  build_st();

  for(int i = 1; i <= M; i++) {
    int a,b;
    std::cin >> a >> b;
    std::cout << lca(a,b) << std::endl;
  }


  return 0;
}
