#include "graph.h"   // 引用库函数文件
#include <queue>
namespace exa {     //请在命名空间内编写代码，否则后果自负
	
	vector<int> solve(vector<vector<datagraph> > & G, int u) {
		std::queue<std::pair<int, int>> que;
		std::vector<int> dis(G.size(), -1);
		que.push(std::make_pair(u-1, 0));
		dis[u-1] = 0;
		while(!que.empty()){
			auto pt = que.front();
			que.pop();
			for(int v = 0; v < G[pt.first].size(); v++){
				const auto vpt = G[pt.first][v];
				if(dis[v] != -1) continue;
				if(vpt.flag){
					que.push(std::make_pair(v, pt.second + 1));
					dis[v] = pt.second + 1;
				}
			}
		}
		return dis;
	}
	
}

