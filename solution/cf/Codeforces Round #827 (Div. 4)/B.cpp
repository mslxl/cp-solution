#include<bits/stdc++.h>

void slove(){
	int n;
	std::cin >> n;
	std::vector<int> seq(n);
	for(int i = 0; i < n ;i++ ){
		std::cin >> seq[i];
	}
	std::sort(seq.begin(), seq.end());
	int last = -1;
	for(auto i: seq){
		if(i > last){
			last = i;
		}else{
			std::cout << "NO" << std::endl;
			return;
		}
	}
	std::cout << "YES" << std::endl;
}
int main(){
	int T;
	std::cin >> T;
	while(T--){
		slove();
	}
	return 0;
}
