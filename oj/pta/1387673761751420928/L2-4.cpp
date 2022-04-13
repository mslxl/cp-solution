#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
using OptionList = std::vector<int>;

int N, M;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> N >> M;
	std::vector<OptionList> scene(N + 1);
	rep(i, 1, N + 1){
		int K;
		std::cin >> K;
		std::vector<int> option(K + 1);
		rep(j, 1, K + 1){
			std::cin >> option[j];
		}
		scene[i] = option;
	}
	
	// simulate
	int current_scene = 1;
	std::map<int, int> saves;
	tout << "start" << std::endl;
	rep(i, 0, M){
		int op,j;
		std::cin >> op >> j;
		if(op == 0){
			// pick a option
			current_scene = scene[current_scene][j];
			tout << "current: " << current_scene << std::endl;
		}else if(op == 1){
			// save
			// at the same time, print current_scene id
			saves[j] = current_scene;
			tout << "!!save " << current_scene << " to " << j << std::endl;
			std::cout << current_scene << std::endl;
		}else if(op == 2){
			// load save
			current_scene = saves[j];
			tout << "load " << current_scene << " from " << j << std::endl;
		}
	}
	std::cout << current_scene;
	
	return 0;
}
