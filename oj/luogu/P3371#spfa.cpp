#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

const int maxn = 1e4 + 17;
const int maxm = 5 * 1e5 +17;
int n,m;

struct Edge{
	ll u,v,w;
	int next;
} edges[maxm];
int head[maxn], eid = 0;
void add_edge(int u ,int v, int w){
	eid++;
	edges[eid].u = u;
	edges[eid].v = v;
	edges[eid].w= w;
	edges[eid].next = head[u];
	head[u] = eid;
}

ll dis[maxn];
bool vis[maxn];
int in_queue_times[maxn]; //统计入列的次数
bool spfa(const int point_start){
	std::queue<int> seq;
	std::fill_n(dis, maxn, INT32_MAX);
	std::fill_n(vis, maxn, false);
	std::fill_n(in_queue_times, maxn, 0);
	seq.push(point_start);
	vis[point_start] = 1;
	dis[point_start] = 0;
	in_queue_times[point_start] = 1;
	
	while(!seq.empty()){
		const int u = seq.front();
		seq.pop();
		vis[u] = false; // !!!!
		for(int node_id = head[u]; node_id != 0; node_id = edges[node_id].next){
			const int v = edges[node_id].v;
			if(dis[v] > dis[u] + edges[node_id].w){
				dis[v] = dis[u] + edges[node_id].w;
				if(!vis[v]){
					in_queue_times[v]++;
					if(in_queue_times[v] >= n){
						return true;
					}
					vis[v] = true;
					seq.push(v);
				}
			}
		}
	}
	return false;
}



int s;
int main(){
	std::cin >> n >> m >> s;
	rep(i, 0, m){
		int u,v,w;
		std::cin >> u >> v >> w;
		add_edge(u,v,w);		
	}
	
	spfa(s);
	
	rep(i, 1, n+1){
		std::cout << dis[i] << ' ';
	}
}
