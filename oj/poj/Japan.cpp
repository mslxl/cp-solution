/**
 * @file Japan.cpp 
 * @brief: poj3067
 * @date: 2022-08-17 23:11:25
 **/

#include<cstring>
#include<string>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

int T;
int N,M,K;
const int maxn = 1e3 + 17;
std::pair<int,int> route[maxn];

int bit[maxn];
#define lowbit(x) ((-x)&(x))
void add(int v, int i){
	for(;i <= K; i += lowbit(i)){
		bit[i]+=v;
	}
}

int prefix(int i){
	int s = 0;
	for(; i > 0; i -= lowbit(i)){
		s+=bit[i];
	}
	return s;
}

int id = 1;

void solve(){
	std::memset(bit, 0,sizeof(bit));
	std::cin >> N >> M >> K;
	for(int i = 0; i < K; i++){
		std::cin >> route[i].first >> route[i].second;
	}	
	std::sort(route, route + K);
	int ans = 0;
	for(int i =0; i < K; i++){
		ans += (i-prefix(route[i].second));
		add(1, route[i].second);
	}
	std::cout << "Test case " << (id++) << ": " << ans;
	
}

int main(){
	
	std::cin >> T;
	while(T--) solve();
}
