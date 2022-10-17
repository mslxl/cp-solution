#include<bits/stdc++.h>
const int maxt = 1e3 + 17, maxm = 1e2 + 17;

int T,M;

int dp[maxt][maxm];

struct Herb{
	int time;
	int value;
} herb[maxm];

int main(){
	std::memset(dp, 0, sizeof(dp));
	std::cin >> T >> M;
	for(int i = 0; i < M; i++){
		std::cin >> herb[i].time >> herb[i].value;	
	}	
	
	for(int m = 0; m < M; m++){
		for(int t = T; t >= 0; t--){
			if(t >= herb[m].time){
				dp[t][m]  = std::max(dp[t-herb[m].time][m-1] + herb[m].value, dp[t][m-1]);
			}else{
				dp[t][m] =  dp[t][m-1];
			}
		}
	}
	
	int max = -1;
	for(int i = 0; i <= T;i++){
		for(int j = 0; j < M; j++){
			max = std::max(max, dp[i][j]);
		}
	}
	std::cout << max;
	
	
	return 0;
}
