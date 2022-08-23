/**
 * @file P_1908_逆序对.cpp 
 * @brief: p1908
 * @date: 2022-08-18 11:18:08
 **/
#include<bits/stdc++.h>
#define lb(x) ((-x)&(x))
int n;
const int maxn = 5 * 5e5;
int data[maxn];
std::tuple<int,int,int> tup[maxn];
int bits[maxn];

void add(int i, int v){
	for(; i <= maxn; i += lb(i))
		bits[i]+=v;
}
int prefix(int i){
	int s = 0;
	for(;i > 0; i-=lb(i)){
		s+=bits[i];
	}
	return s;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
	
	std::cin >> n;
	for(int i = 0; i < n; i++){
        std::cin >> data[i];
        std::get<0>(tup[i]) = data[i];
        std::get<2>(tup[i]) = i;
	}
	
    std::sort(tup, tup + n);
    std::get<1>(tup[0]) = 1;
    for(int i = 1; i < n;i++){
        if(std::get<0>(tup[i]) == std::get<0>(tup[i-1])){
            std::get<1>(tup[i]) = std::get<1>(tup[i-1]);
        }else{
            std::get<1>(tup[i]) = std::get<1>(tup[i-1])+1;
        }
    }
    for(int i = 0; i < n; i++){
        data[std::get<2>(tup[i])] = std::get<1>(tup[i]);
    }

	long long ans = 0;
	for(int i = 0; i < n; i++){
		ans += (i - prefix(data[i]));
		add(data[i], 1);
	}	
	std::cout << ans;
	return 0;
}
