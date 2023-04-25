#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstring>
std::string map[55];
int M, N;
int ans = 0;
std::set<char> flood;
bool vis[55][55];

int color = '9';
void floodfill(int y, int x){
	if(map[y][x] != '0') return;
	if(vis[y][x]) return;
	vis[y][x] = true;
	if(y > 0 && map[y-1][x] == '0') floodfill(y-1, x);
	if(x > 0 && map[y][x-1] == '0') floodfill(y, x-1);
	if(y < M && map[y+1][x] == '0') floodfill(y+1, x);
	if(x < N && map[y][x+1] == '0') floodfill(y, x+1);
}

void colorify(int y, int x){
	if(map[y][x] != '1') return;
	map[y][x] = color;
	if(y > 0 && map[y-1][x] != '0') colorify(y-1, x);
	if(x > 0 && map[y][x-1] != '0') colorify(y, x-1);
	if(y < M && map[y+1][x] != '0') colorify(y+1, x);
	if(x < N && map[y][x+1] != '0') colorify(y, x+1);
}

void judge(int y, int x){
	std::memset(vis, 0, sizeof(vis));
	if(y > 0 && map[y-1][x] == '0'){
		floodfill(y-1,x);
		flood.insert(map[y][x]);
		colorify(y,x);
		if(y > 0 && map[y-1][x] == '0' && !vis[y-1][x]){
			ans++;// island
		}else if(x > 0 && map[y][x-1] == '0' && !vis[y][x-1]){
			ans++;// island
		}else if(y < M && map[y+1][x] == '0' && !vis[y+1][x]){
			ans++;// island
		}else if(x < N && map[y][x+1] == '0' && !vis[y][x+1]){
			ans++;// island
		}
		
	}
	std::memset(vis, 0, sizeof(vis));
	if(x > 0 && map[y][x-1] == '0'){
		floodfill(y-1,x);
		flood.insert(map[y][x]);
		colorify(y,x);
		if(y > 0 && map[y-1][x] == '0' && !vis[y-1][x]){
			ans++;// island
		}else if(x > 0 && map[y][x-1] == '0' && !vis[y][x-1]){
			ans++;// island
		}else if(y < M && map[y+1][x] == '0' && !vis[y+1][x]){
			ans++;// island
		}else if(x < N && map[y][x+1] == '0' && !vis[y][x+1]){
			ans++;// island
		}
	}
	std::memset(vis, 0, sizeof(vis));
	if(y < M && map[y+1][x] == '0'){
		floodfill(y+1,x);
		flood.insert(map[y][x]);
		colorify(y,x);
		if(y > 0 && map[y-1][x] == '0' && !vis[y-1][x]){
			ans++;// island
		}else if(x > 0 && map[y][x-1] == '0' && !vis[y][x-1]){
			ans++;// island
		}else if(y < M && map[y+1][x] == '0' && !vis[y+1][x]){
			ans++;// island
		}else if(x < N && map[y][x+1] == '0' && !vis[y][x+1]){
			ans++;// island
		}
	}
	std::memset(vis, 0, sizeof(vis));
	if(x < N && map[y][x+1] == '0'){
		floodfill(y,x+1);
		flood.insert(map[y][x]);
		colorify(y,x);
		if(y > 0 && map[y-1][x] == '0' && !vis[y-1][x]){
			ans++;// island
		}else if(x > 0 && map[y][x-1] == '0' && !vis[y][x-1]){
			ans++;// island
		}else if(y < M && map[y+1][x] == '0' && !vis[y+1][x]){
			ans++;// island
		}else if(x < N && map[y][x+1] == '0' && !vis[y][x+1]){
			ans++;// island
		}
	}
}



void solve(){
	flood.clear();
	ans = 0;

	std::cin >> M >> N;
	for(int i = 0; i < M; i++){
		std::cin >> map[i];
	}
	
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(map[i][j] != '0' && !flood.count(map[i][j])){
				judge(i, j);
				color++;
			}
		}
	}
	
	std::cout << ans << "\n";
}

int main(){
	int T;
	std::cin >> T;
	while(T--){
		solve();
	}	
	return 0;
}
