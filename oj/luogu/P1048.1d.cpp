#include<bits/stdc++.h>

const int maxt = 1e3 + 17;
const int maxm = 1e2 + 17;

struct herb{
	int time;
	int value;
}h[maxm];

int T,M;

using ll = unsigned long long;

ll dp[maxt];

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> T >> M;
	for(int i = 0; i < M; i++)
		std::cin >> h[i].time >> h[i].value;
	
	for(int m = 0; m < M; m++){
		for(int t = T; t >= 0; t--){
			if(t >= h[m].time){
				dp[t] = std::max(dp[t-h[m].time] + h[m].value, dp[t]);
			}
		}
	}
	
	std::cout << dp[T];
	
}
