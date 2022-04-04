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

	
	ll a[3];
	rep(i,0,3) std::cin >> a[i];
	std::sort(a,a+3);
	std::cout << a[0] << "->" << a[1] << "->" << a[2];
	
	return 0;
}

