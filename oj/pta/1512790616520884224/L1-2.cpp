#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
int main(){
	const double mul_lqti = 2.455, mul_rigid = 1.26;
	double mess_ratio, attr, radius_ration;
	std::cin >> mess_ratio >> attr >> radius_ration; 
	double xiuu;
	if(attr == 0){
		xiuu = mess_ratio * mul_lqti ;
	}else{
		xiuu = mess_ratio * mul_rigid ;
	}
	printf("%.2f %s", xiuu, xiuu * (1.0 / radius_ration) <= 1 ? "^_^" : "T_T");
	return 0;
}
