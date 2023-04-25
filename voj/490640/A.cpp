#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

int main(){
	int a=0,b=0;
	int input;
	rep(i,0,5) {
		std::cin >> input;
		a+=input;
	}
	rep(i,0,5) {
		std::cin >> input;
		b+=input;
	}
	std::cout << (a >= b ? "Blue" : "Red");
}
