#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

const int maxn = 100 + 17;
int N, M, K;

int sets[maxn];
int find(int u){
	while(sets[u] != u)
		u = sets[u];
	return u;
}
int uni(int u, int v){
	sets[find(u)] = find(v);
}

bool enemy[maxn][maxn];

bool is_friend(int x, int y){
	return find(x) == find(y);
}
bool is_enemy(int x, int y){
	return enemy[x][y];
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::memset(enemy, false, sizeof(enemy));
	std::cin >> N >> M >> K;
	rep(i, 0, N + 10){
		sets[i] = i;
	}
	rep(i, 0, M){
		int x, y, re;
		std::cin >> x >> y >> re;
		if(re == 1){
			uni(x,y);
		}else{
			enemy[x][y] = true;
			enemy[y][x] = true;
		}
	}
	rep(i, 0, K){
		int x,y;
		std::cin >> x >> y;
		if(is_friend(x,y) && !is_enemy(x,y)){
			std::cout << "No problem" << std::endl;
		}else if(!is_friend(x,y) && is_enemy(x,y)){
			std::cout << "No way" << std::endl;
		}else if(is_friend(x,y) && is_enemy(x,y)){
			std::cout << "OK but..." << std::endl;
		}else{
			std::cout << "OK" << std::endl;
		}
	}
	
	return 0;
}

