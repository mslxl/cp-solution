#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstring>
#include<queue>
const int maxn = 1e5+17;
struct Edge{
	int to, next;
} e[2 * maxn + 1];

int head[maxn], eid = 0;

void add_edge(int u, int v){
	eid++;
	e[eid].to = v;
	e[eid].next = head[u];
	head[u] = eid;
}

void add_biedge(int u, int v){
	add_edge(u, v);
	add_edge(v, u);
}
#define int long long

const int maxm = maxn / 2;
int n, m;
int parent[maxn];
int depth[maxn];
std::set<std::pair<int,int> > req[maxm];
std::pair<int,int> edge_seq[maxn];

void dfs_parent(int x, int fa){
	parent[x] = fa;
	depth[x] = depth[fa] + 1;
	for(int i = head[x]; i; i = e[i].next){
		if(e[i].to == fa) continue;
		dfs_parent(e[i].to, x);
	}
}

#undef int 
int main(){
	#define int long long
	std::cin >> n >> m;

	for(int i = 0; i < n-1; i++){
		int u, v;
		std::cin >> u >> v ;
		add_biedge(u, v);
		edge_seq[i].first = std::min(u,v);
		edge_seq[i].second = std::max(u,v);
	}
	dfs_parent(1, 0);
	
	for(int i = 0; i < m ;i++){
		int a,b;
		std::cin >> a >>b;
		if(depth[a] > depth[b]){
			std::swap(a,b);
		}
		while(depth[a] != depth[b]){
			req[i].insert({std::min(b, parent[b]), std::max(b, parent[b])});
			b = parent[b];
		}
		if(a == b) continue;
		while(a != b){
			req[i].insert({std::min(b, parent[b]), std::max(b, parent[b])});
			req[i].insert({std::min(a, parent[a]), std::max(a, parent[a])});
			a = parent[a];
			b = parent[b];
		}
	}
	
	for(int i = n-1; i >= 0; i--){
		std::pair<int,int> & edge = edge_seq[i];
		bool found = true;
		for(int j = 0; j < m; j++){
			std::set<std::pair<int,int> > &e = req[j];
			if(!e.count(edge)){
				found = false;
				break;
			}
		}
	
		if(found){
			std::cout << i + 1;
			return 0;
		}
	}
	std::cout << -1;
	return 0;
}


