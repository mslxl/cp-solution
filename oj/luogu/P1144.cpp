#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
int N,M;
const int maxn = 1000000 + 17, maxm = 2000000;
const int modd = 100003;
struct Edge{
	int to;
	int next;
} edges[maxm * 2 + 1];
int head[maxn], eid = 0;

void add_edge(int u, int v){
	eid++;
	Edge& e = edges[eid];
	e.to = v;
	e.next = head[u];
	head[u] = eid;
}
inline void add_biedge(int x, int y){
	add_edge(x,y);
	add_edge(y,x);
}

int min_dis[maxn];
int num_dis[maxn];


void bfs(){
	std::fill_n(min_dis, maxn, INT32_MAX);
	std::queue<int> seq;
	min_dis[1] = 0;
	num_dis[1] = 1;
	
	seq.push(1);
	while(!seq.empty()){
		const auto u = seq.front();
		seq.pop();;
		
		for(int node_id = head[u]; node_id != 0; node_id = edges[node_id].next){
			const int v  = edges[node_id].to;
			if(min_dis[u] + 1 <= min_dis[v]){
				min_dis[v] = min_dis[u] + 1;
				num_dis[v] += num_dis[u];
				num_dis[v] %= modd;
				seq.push(v);
			}
		}
	}
}


int main(){
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
	std::cin >> N >> M;
	rep(i, 0, M){
		int x,y;
		std::cin >> x >> y;
		add_biedge(x,y);
	}
	bfs();
	rep(i,1,N+1) std::cout << num_dis[i] << std::endl;
}
