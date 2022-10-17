#include<bits/stdc++.h>

int n,x;

constexpr int maxn = 1e3 + 17;
constexpr int maxx = 1e3 + 17;
constexpr int maxuse = 1e3 + 17;

using ll = long long;
ll dp[maxx];



struct eny{
	int win;
	int lose;
	int use;
}e[maxn];

int main(){
	std::cin >> n >> x;
	
	for(int i = 0; i < n; i++)
		std::cin >> e[i].lose >> e[i].win >> e[i].use;
	
	for(int i = 0; i < n; i++){
		for(int j = x; j >= 0; j--){
			if(j >= e[i].use){
				dp[j] = std::max(dp[j] + e[i].lose, dp[j - e[i].use] + e[i].win);
			}else{
				dp[j] = dp[j] + e[i].lose;	
			}
		}
	}
	std::cout << (5 * dp[x]); 
	
	return 0;
}
