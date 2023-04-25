#include<bits/stdc++.h>
const std::string data = "5686916124919823647759503875815861830379270588570991944686338516346707827689565614010094809128502533";
int ans = 0;

int monthday[] = {
	0,
    31,
	 28,
	  31, //3
	  30,//4
	  31,//5
	  30,//6
	  31,//7
	  31,//8
	  30,//9
	  	  31,//10
	  	  30,//11
	  	  31//12
};
std::set<std::string> s;

void dfs(int x, std::string cur){
	if(cur.size() == 8){
		if(cur.substr(0,4) == "2023"){
			int month = std::atoi(cur.substr(4, 2).data());
			if(month <= 12 && month >= 1){
				int day = std::atoi(cur.substr(6, 2).data());
				if(day <= monthday[month] && day >= 1){
					if(!s.count(cur)){
						ans++;
					}
					s.insert(cur);
					
				}
				
			}
		}
		return;
	}
	cur += data[x];
	for(int i = x + 1; i < data.size(); i++){
		if(cur.size() == 1 && data[i] != '0'){
			continue;
		}
		if(cur.size() == 2 && data[i] != '2'){
			continue;
		}
		if(cur.size() == 3 && data[i] != '3'){
			continue;
		}
		dfs(i, cur);
	}
}

int main(){
	for(int i = 0; i < data.size() - 8; i++){
		//std::cout << data.substr(i, 8) << std::endl;
		if(data[i] == '2'){
			dfs(i, "");
		}
	}
	std::cout << ans;
	return 0;
	
}
