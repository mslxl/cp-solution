#include<bits/stdc++.h>

#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

const std::size_t maxn = 1e4 + 17;
struct Edge{
	int next, to;
} edges[maxn * 10 + 17];

int head[maxn], eid = -1;

void add_edge(int u,int v){
	eid++;
	assert(eid < (maxn * 10 + 17)); // avoid access-violation
	edges[eid].to = v;
	edges[eid].next = head[u];
	head[u] = eid;
}

int N;
int parent[maxn], depth[maxn];
int max_depth = 1, max_depth_node = maxn;
void read_data(){
	std::fill_n(head, maxn, -1);
	std::fill_n(parent, maxn, -1);
	std::fill_n(depth, maxn, 1);
	std::cin >> N;
	rep(u, 0, N){
		int M;
		int v;
		std::cin >> M;
		rep(_t, 0, M){
			std::cin >> v;
			add_edge(v, u); // reverse graph
		}
	}	
}

void dp(const int u){
	if(u == -1) return;
	test std::cout << "dp " << u << std::endl ;
	if(head[u] == -1 && max_depth <= 1){
		max_depth_node = u;
		return;
	}
	for(int node_id = head[u]; node_id != -1; node_id = edges[node_id].next){
		const int v = edges[node_id].to;
		if(depth[u] + 1 > depth[v]){
			// deeper depth
			depth[v] = depth[u] + 1;
			parent[v] = u;
			test std::cout << "connect " << v << " -> " << u << std::endl;
			
			if(depth[v] > max_depth ){
				max_depth_node = v;
				max_depth = depth[v];
				test std::cout << "remark start point " << max_depth_node << std::endl;
			}else if(depth[v] == max_depth){
				max_depth_node = std::min(max_depth_node, v);
				test std::cout << "remark start point " << max_depth_node << std::endl;
			}
			dp(v);
		}else if(depth[u] + 1 == depth[v]){
			// next node have same depth from different route
			// choose the smaller id
			if(u < parent[v]){
				test std::cout << "override " << v << " -> " << u << std::endl;
				parent[v] = u;
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	read_data();
	if(N == 0){ // ?
		std::cout << 0;
		return 0;
	}
	rep(i, 0, N) dp(i);
	
	std::cout << max_depth << std::endl;
	// max_depth would never be ZERO, normally
	int u = max_depth_node;
	std::cout << u;
	u = parent[u];
	while(u != -1){
		std::cout << ' ' << u;
		u = parent[u];
	}
	return 0;
}
