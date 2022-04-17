#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

const int maxn = 1e4 + 17, maxm = 5 * 1e5 + 17;
int n, m, s;

int graph[maxn][maxn];
int dis[maxn][maxn];
int parent[maxn][maxn];

int main(){
	tout << "INT32_MAX=" << INT32_MAX/2 << std::endl;
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::fill_n(&graph[0][0], maxn * maxn, INT32_MAX/2);
	std::fill_n(&dis[0][0], maxn * maxn, INT32_MAX/2);
	std::fill_n(&parent[0][0], maxn, -1);
	
	
	std::cin >> n >> m >> s;
	rep(i, 0, m){
		int u,v,w;
		std::cin >> u >> v >> w;
		graph[u][v] = w;
		dis[u][v] = w;
		parent[u][v] = u;
	}
	dis[s][s] = 0;
	graph[s][s] = 0;
	
	rep(k, 1, n+1){
		rep(i,1, n+1){
			rep(j, 1, n+1){
				//if(k == i || k == j || i == j) continue;
				if(dis[i][k] + dis[k][j] < dis[i][k]) continue; // avoid overflow
				if(dis[i][k] + dis[k][j] < dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
					parent[i][j] = parent[k][j];
				}
			}
		}
	}
	
	rep(i, 1, n+1){
		std::cout << dis[s][i] << ' ';
	}
	
	
	
	return 0;
}
