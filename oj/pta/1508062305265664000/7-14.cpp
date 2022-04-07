#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)

constexpr int maxn = 1e4 + 17;

struct Peak{
	int to;
	int next;
} nodes[maxn * 2];
int head[maxn], eid = 0;
typedef long long ll;

void add_edge(int u, int v){
	eid++;
	nodes[eid].to = v;
	nodes[eid].next = head[u];
	head[u] = eid;
}
void add_biedge(int u, int v){
	add_edge(u,v);
	add_edge(v,u);
}
int n, m, k;

int bfs(const int start){
	test std::cout << "Shout from " << start << std::endl;
	bool vis[n + 1] = {false};
	std::memset(vis, false, sizeof(vis));
	int max_distance = 0, max_distanc_peak = start;
	
	std::queue<std::pair<int,int>> seq;
	seq.push(std::make_pair(start, 0));
	
	vis[start] = true;
	while(!seq.empty()){
		const auto pt = seq.front();
		seq.pop();
		const int u = pt.first;
		
		for(int node_id = head[u]; node_id != 0; node_id = nodes[node_id].next){
			const int v = nodes[node_id].to;
			if(!vis[v]){
				test std::cout << "Step " << v << " distance " << (pt.second + 1) << std::endl;
				seq.push(std::make_pair(v, pt.second + 1));
				if(pt.second + 1 == max_distance){		
					max_distanc_peak = std::min(max_distanc_peak, v);
				}else if(pt.second + 1 > max_distance){
					max_distance = pt.second + 1;
					max_distanc_peak = v;
				}
				vis[v] = true;
			}
		}
		
	}
	return max_distanc_peak == start ? 0 : max_distanc_peak;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> m >> k;
	rep(i,0, m){
		int u,v;
		std::cin >> u >> v;
		add_biedge(u, v);
	}
	rep(i, 0, k){
		int ask;
		std::cin >> ask;
		std::cout << bfs(ask) << std::endl;
	}
	return 0;
}

