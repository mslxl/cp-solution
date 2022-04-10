#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
const int maxn = 1e4 + 17; 
struct Edge{
	int next, to;
} edges[maxn];
int head[maxn], eid = 0;

void add_edge(int u, int v){
	eid++;
	Edge& e = edges[eid];
	e.to = v;
	e.next = head[u];
	
	head[u] = eid;
}
int N;

template<typename T>
bool vector_lt(const T& lhs, const T& rhs){
	if(lhs.size() != rhs.size()){
		return lhs.size() > rhs.size();
	}else{
		return lhs < rhs;
	}
}

std::deque<int> dfs(int node){
	
	const int u = node;
	
	if(head[u] == -1){
		// end-point
		std::deque<int> route;
		route.push_front(u);
		return route;
	}else{
		std::deque<int> best;
		for(int node_id = head[node]; node_id != -1; node_id = edges[node_id].next){
			const int v = edges[node_id].to;
			std::deque<int> n = dfs(v);
			if(vector_lt(n, best)){
				best = n;
			}
		}
		best.push_front(u);
		return best;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::fill_n(head, maxn, -1);

	std::cin >> N;
	rep(i, 0, N){
		int k, x;
		std::cin >> k;
		while(k--){
			std::cin >> x;
			add_edge(i, x);
		}
	}
	
	std::deque<int> priority_route = dfs(0); 
	rep(i, 1, N) {
		const std::deque<int> n = dfs(i);
		if(vector_lt(n,priority_route)){
			priority_route = n;
		}
	}

	std::cout << priority_route.size() << std::endl;
	std::cout << priority_route[0];
	rep(i,1,priority_route.size()) std::cout << ' ' << priority_route[i];
			
	return 0;
}

