/**

 4 5
 ***#*
 *#***
 ***#*
 *#***
 0 4
 3 0
  
  7
  
  第1行：地图大小N，M
  第2~N+2行：N x M的地图，左上角坐标为(0,0)，右下角坐标为(N-1,M-1)
  第N+3行：起点坐标x1 y1
  第N+4行：终点坐标x2 y2
  
  输出格式：
  1行：最少步数，若无解则输出 0
 */

#include<bits/stdc++.h>
int w,h;
//它真的好温柔，甚至不提供数据范围
std::vector<std::string> map;
std::vector<std::vector<int>> dis;

int offset[][2] = {
	{0,-1},
	{-1,0},
	{0,1},
	{1,0}
};

inline std::pair<int,int> move_pt(const std::pair<int,int> & pt, int act)   {
	return std::make_pair(pt.first + offset[act][0], pt.second + offset[act][1]);
}

inline bool is_pt_valid(const std::pair<int,int>&pt){
	// 地图的w和h是反着的，头歌你做的好啊
	bool valid_x = (pt.first >= 0 && pt.first < h);
	bool valid_y = (pt.second >= 0 && pt.second < w);
	return valid_x && valid_y && map[pt.first][pt.second] == '*';
}

	
int bfs(int x,int y, int tx, int ty){
	std::queue<std::pair<int,int>> que;
	que.push(std::make_pair(x,y));
	dis[x][y] = 0;
	while(!que.empty()){
		auto pt = que.front();
		que.pop();
		if(pt.first == tx && pt.second == ty){
			return dis[tx][ty];
		}
		for(int act = 0; act < 4; act++){
			auto mv_pt = move_pt(pt, act);
			if(is_pt_valid(mv_pt) && dis[mv_pt.first][mv_pt.second] == -1){
				dis[mv_pt.first][mv_pt.second] = dis[pt.first][pt.second] + 1;
				que.push(mv_pt);
			}
		}
	}
	return 0;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> h >> w;
	for(int i = 0 ; i < h;i++){
		std::string line;
		std::cin >> line;
		std::vector<int> tmp(line.size(), -1);
		map.emplace_back(std::move(line));
		dis.emplace_back(std::move(tmp));
	}
	int sx, sy;
	int tx, ty;
	std::cin >> sx >> sy >> tx >> ty;
	std::cout << bfs(sx,sy, tx,ty);
	
	return 0;
}
