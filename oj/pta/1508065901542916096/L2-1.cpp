#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = s; i < e; i++)
typedef long long ll;
bool valid(const std::vector<int>& target, const int max_depth){
	std::stack<int> sk;
	int idx_data = 0, idx_target = 0;
	while(true){
		sk.push(++idx_data);
		if(sk.size() > max_depth){
			return false;
		}
		test std::cerr << "Push number: " << idx_data << std::endl;
		while(!sk.empty() && sk.top() == target[idx_target]){
			test std::cerr << "Pop number: " << sk.top() << std::endl;
			sk.pop();
			idx_target++;
		}
		if(idx_data == target.size()){
			return idx_data == idx_target;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int M, N, K;
	std::cin >> M >> N >> K;
	std::vector<int> seq(N);
	rep(i, 0, K) {
		rep(j, 0, N){
			std::cin >> seq[j];
		}
		if(valid(seq, M)){
			std::cout << "YES" << std::endl;
		}else{
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}
