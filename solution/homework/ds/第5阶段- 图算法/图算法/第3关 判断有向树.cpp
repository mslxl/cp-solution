#include "graph.h"   // 引用库函数文件
namespace exa {     //请在命名空间内编写代码，否则后果自负
	const int maxn = 100 + 17;
	
	
	int parent[maxn];
	
	int find(int x) {
		while(parent[x] != x){
			x = parent[x];
		}
		return x;
	}
	
	bool joint(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return false;
		parent[y] = x;
		return true;
	}
	
	bool solve(vector<vector<datagraph> > & G) {
		int indegree[maxn];
		for(int i = 0; i< maxn; i++) {
			parent[i] = i;
			indegree[i] = 0;
		}
		
		
		for(int u = 0; u < G.size(); u++){
			for(int v = 0; v < G[u].size(); v++){
				auto data = G[u][v];
				if(data.flag){
					indegree[v]++;
					if(!joint(u,v)) {
						//printf("%d -> %d", u, v);
						return false;
					}
				}
			}
		}
		
		for(int i = 0; i < maxn; i++){
			if(indegree[i] >1) {
				return false;
			}
		}
		return true;
		
	}
	
}

