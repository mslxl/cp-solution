#include<bits/stdc++.h>
using stick = std::pair<int, int>;
using ll = long long;

int main(){
	int n;
	std::cin >> n;
	std::vector<stick> seq(n);
	std::vector<bool> vis(n);
	std::fill(vis.begin(), vis.end(), false);
	
	for(int i = 0; i < n; i++){
		stick &s = seq[i];
		std::cin >> s.first >> s.second;
	}
	
	std::sort(seq.begin(), seq.end(), std::greater<stick>());
	

	
	ll preceed = 0;
	ll time = 0;
	auto last = std::make_pair(0,0);
	while(preceed < n){
		std::size_t i = 0;
		while(i < seq.size()){
			if(vis[i]){
				i++;
				continue;
			}
			last = seq[i];
			vis[i] = true;
			preceed++;
			time++;
			i++;
			break;
		}
		
		for(; i < seq.size(); i++){
			if(vis[i]) continue;
			const auto &s = seq[i];
			if(s.first <= last.first && s.second <= last.second){
				preceed++;
				vis[i] = true;
				last = s;
			}
		}
	}
	std::cout << time;
	

	return 0;
}
