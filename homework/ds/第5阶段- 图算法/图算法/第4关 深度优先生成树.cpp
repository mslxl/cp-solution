#include "graph.h"   // ÒýÓÃ¿âº¯ÊýÎÄ¼þ
namespace exa {     //ÇëÔÚÃüÃû¿Õ¼äÄÚ±àÐ´´úÂë£¬·ñÔòºó¹û×Ô¸º
	
	
	bool vis[100];
	void dfs(std::vector<std::vector<datagraph>> &G, int u, std::vector<int> & seq){
		for(int v = 0; v < G[u].size(); v++){
			if(G[u][v].flag & !vis[v] ){
				seq.push_back(v+1);
				vis[v] = true;
				dfs(G, v, seq);
			}
		}
	}
	
	vector<int> solve(vector<vector<datagraph> > & G, int u) {
		for(int i = 0; i< 100; i++) vis[i] = false;
		std::vector<int> ret;
		ret.push_back(u);
		u--;
		vis[u] = true;
		dfs(G, u, ret);
		return ret;
	}
	
}

