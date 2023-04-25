#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

int matrix[117][117];

int main(){
	int n,k,x;
	std::cin >> n >> k >> x;
	
	rep(y, 0, n){
		rep(x, 0, n){
			std::cin >> matrix[y][x];
		}
	}
	
	
	
	int down =0 ;
	for(int dx = 1; dx < n; dx += 2){
		down++;
		if(down > k){
			down = 1;
		}
		for(int dy = n; dy-down >=0; dy--){
			matrix[dy][dx] = matrix[dy-down][dx];
		}
		for(int dy = 0; dy < down; dy++){
			matrix[dy][dx] = x;
		}
	}
	
//	tout << "-------------" << std::endl;
//	rep(dy, 0, n){
//		
//		rep(dx, 0, n){
//			tout << matrix[dy][dx] << ' ';
//		}
//		tout << std::endl;
//		
//	}
//	tout << "-------------" << std::endl;
		
	rep(j, 0, n){
		ll sum = 0;
		if(j != 0) std::cout << ' ';
		rep(i, 0, n){
			sum+=matrix[j][i];
		}
		std::cout << sum;
	}
}
