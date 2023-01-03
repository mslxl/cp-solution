#include<bits/stdc++.h>
const int maxm = 1e4 + 17;
const int maxt = 1e7 + 17;
const int maxmt = 1e7 + 17;

int t,m;

struct herb{
	int time;
	int value;
} h[maxm];

using ll = long long;
ll dp[maxmt];

int main(){
	std::cin >> t >> m;
	for(int i = 0; i < m; i++) {
		std::cin >> h[i].time >> h[i].value;
	}
	
	for(int mi = 0; mi < m; mi++){
		for(int ti = h[mi].time; ti <= t; ti++){
			dp[ti] = std::max(dp[ti], dp[ti - h[mi].time] + h[mi].value);
		}
	}
	std::cout << dp[t];
	
	return 0;
}
