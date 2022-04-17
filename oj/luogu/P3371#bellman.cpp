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
ll dis[maxn];
struct Edge{
	ll u,v,w;
} edges[maxm];

bool bellman_ford(const int start_point){
	std::fill_n(dis, maxn, INT32_MAX);
	dis[start_point] = 0;
	rep(i, 0, n){ // 做松弛操作 n-1 次
		bool flag = false;
		rep(j, 0, m){
			if(dis[edges[j].v] > dis[edges[j].u] + edges[j].w){
				dis[edges[j].v] =  dis[edges[j].u] + edges[j].w;
				flag = true;
			}
		}
		if(!flag) return false;
	}
	rep(j, 0, m){ // 如果还能松弛，证明存在负环
		if(dis[edges[j].v] > dis[edges[j].u] + edges[j].w){
			return true;			
		}
	}
	return false;
}

std::istream & operator >> (std::istream& is, Edge& rhs){
	return is >> rhs.u >> rhs.v >> rhs.w;
}
int s;
int main(){
	std::cin >> n >> m >> s;
	rep(i, 0, m){
		std::cin >> edges[i];		
	}
	bool f = bellman_ford(s);
	
	tout << "Circle :" << f << std::endl;
	rep(i, 1, n+1){
		std::cout << dis[i] << ' ';
	}
}
