#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::string A,B;
	getline(std::cin ,A);
	getline(std::cin ,B);
	for(const auto& item: A){
		if(B.find(item) != -1) continue;
		std::cout << item;
	}
	return 0;
}

