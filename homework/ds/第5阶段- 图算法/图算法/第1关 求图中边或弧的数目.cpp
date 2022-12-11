#include "graph.h"  // 引用库函数文件
namespace exa {     //请在命名空间内编写代码，否则后果自负
	
	//using ll = unsigned long long;
	int solve(vector<vector<datagraph> > & G) {
		int cnt = 0;
		bool direct = false;
		for(const auto& vec: G){
			for(const auto& edge: vec){
				if(edge.flag){
					cnt++;
					direct = edge.direct;
				}
			}
		}
		if(direct){
			return cnt;
		}else{
			return cnt / 2;
		}
	}
	
}

