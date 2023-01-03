#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

const int maxm = 2 * 1e5 * 2 + 17;
const int maxn = 5000 + 17;

struct Edge {
	int next;
	int weight, to, from;
	bool operator < (const Edge& rhs) const {
		return this->weight > rhs.weight;
	}
} edges[maxm];
int head[maxn], eid = 0;

bool best_matched[maxn];
int prim(const int start) {
	ll ans = 0;
	
	std::fill_n(best_matched, maxn, false);
	std::priority_queue<Edge> seq;
	
	best_matched[start] = true;
	for(int node_id = head[start]; node_id != 0; node_id = edges[node_id].next){
		seq.push(edges[node_id]);
	}
	
	while(!seq.empty()){
		const Edge edge = seq.top();
		seq.pop();
		if(best_matched[edge.to]) continue;
		best_matched[edge.to] = true;
		tout << edge.from << " --> " << edge.to << "(" << edge.weight << ")" << std::endl;
		ans += edge.weight;
		for(int node_id = head[edge.to]; node_id != 0; node_id = edges[node_id].next){
			const int v = edges[node_id].to;
			if(best_matched[v]) continue;
			seq.push(edges[node_id]);
		}
	}

	return ans;
}



void add_edge(int u, int v, int w) {
	eid++;
	assert(eid < maxm);
	edges[eid].to = v;
	edges[eid].from = u;
	edges[eid].weight = w;
	edges[eid].next = head[u];
	head[u] = eid;
}

void add_biedge(int u, int v,int w){
	add_edge(u,v,w);
	add_edge(v,u,w);
}

int N, M;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::fill_n(head, maxn, 0);
	std::cin >> N >> M;
	rep(i,0,M){
		int u,v,w;
		std::cin >> u >> v >> w;
		add_biedge(u,v,w);
	}
	int ans = prim(1);
	bool con = true;
	rep(i, 1, N+1){
		con = con && best_matched[i];
	}
	if(con)
		std::cout << ans;
	else
		std::cout << "orz";
	return 0;
}
