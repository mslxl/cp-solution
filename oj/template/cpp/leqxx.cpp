const int max_node = 1e5 + 17;
const int max_edge = 1e5 + 17;
struct Edge{
  int to, next;
}edges[max_edge];

int head[max_node], eid=0;

void add_edge(int u,int v){
  eid++;
  edges[eid].to = v;
  edges[eid].next = head[u];
  head[u] = eid;
}

void add_biedge(int u,int v){add_edge(u,v), add_edge(v,u);}