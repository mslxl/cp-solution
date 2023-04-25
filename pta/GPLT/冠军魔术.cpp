#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;
bool is_coin = false;
int initial, push;
int main(){
	std::cin >> initial >> push;
	while(push--){
		if(is_coin){
			initial *= 2;	
		}
		is_coin = !is_coin;
	}
	std::cout << ((int)is_coin) << ' ' << initial;
	
	return 0;
}
