/**
 * @file Starts.cpp 
 * @brief: poj2352
 * @date: 2022-08-17 09:59:36
 * 
 **/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define lowbit(x) ((-x)&x)
const int maxn = 1.2e6;
int bit[maxn];
int ans[maxn];
std::pair<int,int> stars[15000];
int T;
void add(int a, int x){
	a++;
	for(int i = a; i <= maxn; i+=lowbit(i)){
		bit[i]+=x;
	}
}
int prefix(int i){
	i++;
	int s = 0;
	for(; i > 0; i-=lowbit(i)){
		s+= bit[i];
	}
	return s;
}
int main(){
	scanf("%d", &T);
	for(int i = 0; i < T;i++){
		scanf("%d%d", &stars[i].second, &stars[i].first);
	}
	std::sort(stars, stars + T);
	for(int i = 0; i < T;i++){
		add(stars[i].second, 1);
		//printf("star (%d,%d) is a %d level star\n", stars[i].second, stars[i].first, prefix(stars[i].second)-1);
		ans[prefix(stars[i].second)-1]++;
	}
	for(int i = 0; i <T; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}
