#include<vector>
#include<iostream>
#include<algorithm>
int main(){
	int T;
	std::cin >> T;
	std::vector<int> seq(T);
	for(int i = 0; i < T; i++){
		std::cin >>seq[i];
	}
	int Q;
	std::cin >> Q;
	for(int i = 0; i < Q; i++){
		int t;
		std::cin >> t;
		auto ret = std::equal_range(seq.begin(), seq.end(), t);
		std::cout << t << " at order array position [" << (ret.first - seq.begin()) << "," << (ret.second - seq.begin() - 1) << "]\n";
	}
	
}
