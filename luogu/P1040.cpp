#include<bits/stdc++.h>
constexpr int maxn = 30 + 17;


using ll = unsigned long long;

template<typename T>
using arr = std::array<T, maxn>;


arr<arr<ll>> dp;
arr<arr<int>> root;

std::array<ll, maxn> seq;
int n;

void print_preorder(int l, int r, int last = -1){
	if(l >= r) {
		if(l == last) return;
		std::cout << l + 1 << " ";
		return;
	}
	int k = root[l][r];

	std::cout << root[l][r] + 1 << " ";
	print_preorder(l, k-1, k);
	print_preorder(k+1, r, k);
}


int main(){
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> seq[i];
		dp[i][i] = seq[i];
		root[i][i] = i;
	}
	
	for(int len = 1; len < n; len++){
		for(int i = 0; i + len < n; i++){
			const int l = i;
			const int r = i + len;
			
			for(int k = l; k <= r; k++){
				ll left_mark = 0;
				ll right_mark = 0;
				if(l == k){
					left_mark = 1;
				}else{
					left_mark = dp[l][k-1];
				}
				
				if(k == r){
					right_mark = 1;
				}else{
					right_mark = dp[k+1][r];
				}
				ll mark = dp[k][k] + left_mark * right_mark;
				if(mark > dp[l][r]){
					dp[l][r] = mark;
					root[l][r] = k;
					//std::cout << "[" << l << ", " << r << "]: " << k << " mark " << dp[l][r] << std::endl;
				}
			}
		}
	}
	
	std::cout << dp[0][n-1] << std::endl;
	print_preorder(0, n-1);
	
	
	return 0;
}
