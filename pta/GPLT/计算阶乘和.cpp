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
	ll N;
	std::cin >> N;
	ll ct = 1, sum = 0;
	rep(i, 1, N+1){
		ct*=i;
		sum += ct; 
	}
	std::cout << sum;
	return 0;
}

