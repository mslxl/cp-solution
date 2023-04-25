#include<bits/stdc++.h>

constexpr int max_coop = int(1e9-1);
constexpr int min_coop = -max_coop;
using coop = std::pair<int,int>;

void solve(){
	int N;
	std::cin >> N;
	std::vector<coop> points(N);
	
	for(int i = 0 ; i < N; i++){
		std::cin >> points[i].first >> points[i].second;
	}
	
	std::sort(points.begin(), points.end(), [](const coop& lhs, const coop& rhs){
		if(lhs.second != rhs.second){
			return lhs.second < rhs.second;
		}else{
			return lhs.first < rhs.first;
		}
	});
	
	int fst_allow_y = points[points.size() / 2 - 1].second;
	int lst_allow_y = points[points.size() / 2].second;
	int center_y = fst_allow_y + (lst_allow_y - fst_allow_y) / 2;
	std::cout << int(points[points.size()/2 -1].first + 1e8) << " " << center_y + 1 << " " << int(points[points.size()/2 -1].first - 1e8) << " " << center_y - 1;
}

int main(){
	int T;
	std::cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
