#include<bits/stdc++.h>
#define rep(i,s,e) for(int i = s; i < e; i++)
#define fors(i,s,e) rep(i,s,e+1)

const int maxn = 5 * 1e5 + 17;
int N,M,S;

struct Edge{
	int to,next;
} edges[maxn << 1];

int head[maxn], eid;
void add_edge(int u, int v){
	eid++;
	edges[eid].to = v;
	edges[eid].next = head[u];
	head[u] = eid;
}

int st[maxn][21];
int depth[maxn];
int lg[maxn];

void generate_lg_optimize(){
	for(int i = 1; i <= maxn; i++){
		lg[i] = lg[i-1] + (1 << lg[i-1] == i);
	}
}


void dfs(int node, int father){
	st[node][0] = father;
	depth[node] = depth[father] + 1;
	
	
	for(int i = 1; i <= lg[depth[node]]; i++){
		st[node][i] = st[st[node][i-1]][i-1];
	}
	
	for(int id = head[node]; id != 0; id = edges[id].next){
		if(edges[id].to != father) dfs(edges[id].to, node);
	}
}

int lca(int x, int y){
	if(depth[x] < depth[y]){
		std::swap(x,y);
	}
	while(depth[x] > depth[y]){
		x = st[x][lg[depth[x] - depth[y]] - 1];
	}
	
	if(x == y) return x;
	
	for(int k = lg[depth[x]] - 1; k >= 0; k--){
		if(st[x][k] != st[y][k]){
			x = st[x][k];
			y = st[y][k];
		}
	}
	return st[x][0];
	
}

int main(){
	generate_lg_optimize();
	std::cin >> N >> M >> S;
	rep(i,0,N-1){
		int u,v;
		std::cin >> u >> v;
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(S,0);
	rep(i,0,M){
		int x,y;
		std::cin >> x >> y;
		std::cout << lca(x,y) << std::endl;
	}
	return 0;
}
