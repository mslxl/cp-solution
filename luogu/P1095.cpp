// Problem: P1095 [NOIP2007 普及组] 守望者的逃离
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1095
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
int M, S, T;
const int MAXT = 3e5, MAXM = 1e3, MAXS = 1e8;
int dp[MAXT];
int main(){
	std::cin >> M >> S >> T;
	std::memset(dp, 0, sizeof(dp));
	int m = M;
	for(int i = 1; i <= T;i++){
		if(m >= 10){
			dp[i] = dp[i-1] + 60;
			m-=10;
		}else{
			dp[i] = dp[i-1] + 17;
			if(i - (int)std::ceil(1.0 * (10 - m)/4) - 1 >= 0){
				if(dp[i - (int)std::ceil(1.0 * (10 - m)/4) - 1] + 60 > dp[i]){
					dp[i] = std::max(dp[i], dp[i - (int)std::ceil(1.0 * (10 - m)/4) - 1] + 60);
					m += 4*std::ceil(1.0 * (10 - m)/4);
					m -= 10;
				}
			}
		}
		std::cerr << i << "->" << dp[i] << "\t("<< m << "\n";
		if(dp[i] >= S){
			std::cout << "Yes\n" << i;
			return 0;
		}
	}
	
	int ans = 0;
	for(int j = 0; j <= M; j++){
		ans = std::max(ans, dp[j]);
	}
	std::cout << "No\n" << ans;
	
	return 0;	
}