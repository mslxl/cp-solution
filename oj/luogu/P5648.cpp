#include<bits/stdc++.h>

const int maxn = 5e5 + 17;
int n,t;
std::vector<int> seq;

int tree[maxn * 4];

constexpr int left_node(int i){
	return 2 * i;
}

constexpr int right_node(int i){
	return 2 * i + 1;
}




int main(){
	std::ios::sync_with_stdio(false);
	std::cin >> n >> t;
	seq.resize(n);
	for(int i = 0; i < n; i++){
		std::cin >> seq[i];
	}
	
	
}
