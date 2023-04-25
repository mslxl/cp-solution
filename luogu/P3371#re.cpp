#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
const int maxm = 5 * 1e5 + 17;
const int maxn = 1e5 + 17;


struct Edge{
	int next;
	int to, length;
} edges[maxm];
int head[maxn] = {0}, eid = 0;

int distance[maxn];
bool best_match[maxn];
void dijkstra(const int start){
	distance[start] = 0;
	std::fill_n(best_match, maxn, false);
	struct PairCmpImpl{
		bool operator () (const std::pair<int,int>& lhs,const std::pair<int,int>& rhs){
			return lhs.second > rhs.second; 
		}
	};
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, PairCmpImpl> seq; // pair<point-id, length>
	seq.push(std::make_pair(start, 0));
	while(!seq.empty()){
		const std::pair<int, int> pt = seq.top();
		const int u = pt.first;
		seq.pop();
		if(best_match[u]) continue; // already handled! skip
		int u_dis = distance[u] = pt.second;
		best_match[u] = true;
		
		for(int node_id = head[u]; node_id != 0; node_id = edges[node_id].next){
			const Edge v = edges[node_id];
			if(best_match[v.to]) continue;
			seq.push(std::make_pair(v.to, u_dis + v.length));
		}
	}
}

void add_edge(int u, int v, int w){
	eid++;
	edges[eid].length = w;
	edges[eid].to = v;
	edges[eid].next = head[u];
	head[u] = eid;
}
int n, m, s;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::fill_n(head, maxn, 0);
	std::fill_n(distance, maxn, INT32_MAX);
	std::cin >> n >> m >> s;
	rep(i, 0, m){
		int u, v, w;
		std::cin >> u >> v >> w;
		add_edge(u,v ,w);
	}
	dijkstra(s);
	rep(i, 1, n+1){
		std::cout << distance[i] << ' ';
	}
	
	return 0;
}
