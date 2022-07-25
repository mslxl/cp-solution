#include<bits/stdc++.h>

void solve(){
	int n;
	std::cin >> n;
	std::vector<int> seq(n);
	std::vector<std::pair<int,int>> res;
	for(int i = 0; i < n; i++){
		std::cin >> seq[i];
	}	
	auto begin = seq.begin();
	
	while(begin != seq.end()){
		auto nw = std::upper_bound(begin, seq.end(), *begin);
		if(nw - begin == 1){
			std::cout << "-1\n";
			return;
		}else{
			res.push_back({begin - seq.begin() + 1, nw-seq.begin() });
		}
		begin = nw;
	}
	for(const auto &item : res){
		std::cout << item.second<< " ";
		for(int i = item.first; i < item.second; i++){
			std::cout  << i<< " ";
		}
	}
	std::cout << std::endl;

	
}

int main(){
	int T;
	std::cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
