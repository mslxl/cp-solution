#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

bool is_prime(int num){
	tout << "test " << num << std::endl;
	if(num == 1) return false;
	for(int i = 2; i*i <= num; i++){
		if(num % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int m, n;
	int ans = 0;
	std::cin >> m >> n;
	for(int p = m; p <= n - 2; p++){
		if(!is_prime(p)) continue;
		for(int q = p+1; q <= n-1;q++){
			if(!is_prime(q)) continue;
			for(int r = q + 1; r <= n; r++){
				if(!is_prime(r)) continue;
				if(is_prime(p * q + r) && is_prime(q*r + p) && is_prime(r*p + q)){
 					tout << p << ", " << q << ", " << r << std::endl;
					ans++;
				}
			}
		}
	}
	std::cout << ans;
}
