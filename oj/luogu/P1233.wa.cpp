#include<bits/stdc++.h>
int n;
using stick = std::pair<int,int>;


struct stick_cmp{
	bool operator()(const stick& lhs, const stick& rhs){
		return lhs.first > rhs.first || lhs.second > rhs.second;
	}
};

int main(){
	std::cin >> n;
	std::vector<stick> seq(n);
	for(int i = 0; i < n; i++){
		stick &s = seq[i];
		std::cin >> s.first >> s.second;
	}
	stick_cmp cmp;
	std::sort(seq.begin(), seq.end(), std::greater<stick>());
	
	stick lst_stick = std::make_pair(0,0);
	int time = 0;
	for(auto& s: seq){
		std::cout << "process " << s.first << " " << s.second << std::endl;
		if(cmp(s, lst_stick)){
			std::cout << "++" << std::endl;
			time++;
		}
		
		lst_stick = s;
	}
	std::cout << time;
	return 0;
}
