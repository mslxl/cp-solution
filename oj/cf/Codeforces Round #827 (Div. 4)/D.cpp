#include<bits/stdc++.h>

bool is_coprime(int a, int b){
	return std::__gcd(a,b) == 1;
}

void slove(){
	int n;
	std::cin >> n;
	std::vector<std::pair<int,int>> seq(n);
	for(int i = 0; i < n; i++){
		std::cin >> seq[i].first;
		seq[i].second = i + 1;
	}
	std::sort(seq.begin(), seq.end(), [](const std::pair<int,int>&lhs, const std::pair<int,int> &rhs){
		if(lhs.first == rhs.second){
			return lhs.second < rhs.second;
		}else{
			return lhs.first > rhs.first;
		}
	});
	auto end = std::unique(seq.begin(), seq.end(), [](const std::pair<int,int> & lhs, const std::pair<int,int> & rhs){
		return lhs.first == rhs.first;
	});
	seq.erase(end, seq.end());
	
	std::sort(seq.begin(), seq.end(), [](const std::pair<int,int>&lhs, const std::pair<int,int> &rhs){
		return lhs.second > rhs.second;
	});
	
	int max_value = -1;
	for(int i = 0; i < seq.size(); i++){
		for(int j = i; j < seq.size(); j++){
			if(is_coprime(seq[i].first, seq[j].first)){
				max_value = std::max(max_value, seq[i].second + seq[j].second);
			}		
		}
	}	
	std::cout << max_value << std::endl;
}
int main(){
	int T;
	std::cin >> T;
	while(T--){
		slove();
	}
	return 0;
}
