#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstring>
#include<queue>
const int maxn = 1e5+17;
struct Edge{
	int to, next;
	int cost;
} e[2 * maxn + 1];

int head[maxn], eid = 0;

void add_edge(int u, int v, int c){
	eid++;
	e[eid].to = v;
	e[eid].cost = c;
	e[eid].next = head[u];
	head[u] = eid;
}

void add_biedge(int u, int v, int c){
	add_edge(u, v, c);
	add_edge(v, u, c);
}
#define int long long
int N, K;
int route[maxn];
int rt = 1;
int parent[maxn];
int parent_cost[maxn];
int depth[maxn];
int st[maxn][31];
int st_cost[maxn][31];

void build_st(){
	for(int i = 1; i <= N; i++){
		st[i][0] = parent[i];
		st_cost[i][0] = parent_cost[i];
	}
	for(int j = 1; j < 31; j++){
		for(int i = 1; i <= N; i++){
			st[i][j] = st[st[i][j-1]][j-1];
			st_cost[i][j] = st_cost[i][j-1] + st_cost[st[i][j-1]][j-1];
		}
	}
}

int LCA(int x, int y){
	if(depth[x] > depth[y]) std::swap(x, y);
	int cost_y = 0;
	int cost_x = 0;
	for(int k = 30; k >= 0; k--){
		// y is deeper
		if(depth[st[y][k]] >= depth[x] ){
			cost_y += st_cost[y][k];
			y = st[y][k];

		}
	}
	if(x == y){
		return cost_x + cost_y;
	}
	
	for(int k = 30; k >= 0; k--){
		if(depth[st[y][k]] != depth[st[x][k]]){
			cost_y += st_cost[y][k];
			cost_x += st_cost[x][k];
			y = st[y][k];
			x = st[x][k];
		}
	}
	cost_x += parent_cost[x];
	cost_y += parent_cost[y];
	return cost_x + cost_y;
}

void dfs_parent(int x, int fa, int value){
	parent[x] = fa;
	parent_cost[x] = value;
	depth[x] = depth[fa] + 1;
	for(int i = head[x]; i; i = e[i].next){
		if(e[i].to == fa) continue;
		dfs_parent(e[i].to, x, e[i].cost);
	}
}

#undef int 
int main(){
	#define int long long
	std::cin >> N >> K;
	if(K == 1) {
		std::cout << 0;
		return 0;
	}
	for(int i = 0; i < N-1; i++){
		int u, v, t;
		std::cin >> u >> v >> t;
		add_biedge(u, v, t);
	}
	for(int i = 0; i < K; i++){
		std::cin >> route[i];
	}
	dfs_parent(rt, 0, 0);
	build_st();
	int total = 0;
	for(int i = 1; i < K; i++){
		total += LCA(route[i-1], route[i]);
	}
	std::cout << total - LCA(route[0], route[1]);
	for(int i = 1; i+1 < K; i++){
		std::cout << " " << total - LCA(route[i-1], route[i]) - LCA(route[i], route[i+1]) + LCA(route[i-1], route[i+1]);
	}
	if(K > 2){
		std::cout << " " << total - LCA(route[K-2], route[K-1]);
	}
	return 0;
}


