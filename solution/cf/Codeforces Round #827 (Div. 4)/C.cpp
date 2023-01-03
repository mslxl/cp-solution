#include<bits/stdc++.h>

std::vector<std::string> read_map(){
	std::vector<std::string> map;
	std::string line;
	std::getline(std::cin ,line);
	while(line.size() > 0){
		map.push_back(line);
		if(std::cin){
			std::getline(std::cin, line);
		} else {
			break;
		}
		
	}
	return map;
}

struct cpos{
	int x,y;
	char color;
};

cpos find_one_cpos(const std::vector<std::string>& map){
	for(std::size_t y = 0; y < map.size(); y++){
		for(std::size_t x = 0; x < map[y].size(); x++){
			if(map[y][x] != '.'){
				return cpos{
					int(x),int(y), map[y][x]
				};
			}
		}
	}
	return cpos{
		-1,-1, '.'
	};
}

void slove(){
	auto map = read_map();
	auto last_cp = find_one_cpos(map);
	auto last_color = last_cp.color;
	while(true){
		if(last_cp.color == 'B'){
			for(int i = 0; i < map.size(); i++){
				if(map[i][last_cp.x] == 'R'){
					last_cp = cpos{
						last_cp.x, i, 'R'
					};
					break;
				}
			}
		}else{
			for(int i = 0; i < map[last_cp.y].size(); i++){
				if(map[last_cp.y][i] == 'B'){
					last_cp = cpos {
						i, last_cp.y, 'B'
					};
					break;
				}
			}
		}
		
		if(last_cp.color == last_color){
			std::cout << last_color << std::endl;
			return;
		}else{
			last_color = last_cp.color;
		}
	}
}

int main(){
	int T;
	std::cin >> T;
	std::string trash;
	std::getline(std::cin, trash);
	std::getline(std::cin, trash);
	std::getline(std::cin, trash); 
	while(T--){
		slove();
	}
}
