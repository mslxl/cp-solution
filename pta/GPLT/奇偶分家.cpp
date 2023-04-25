#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
const int maxn = 1000 + 17;
int even = 0, odd = 0;
int N;
typedef long long ll;
int main(){
	std::cin >> N;
	int num;
	for(int i = 0; i < N; i++){
		std::cin >> num;
		if(num % 2 == 0){
			even++;
		}else{
			odd++;
		}
	}
	std::cout << odd << ' ' << even;
	
	return 0;
}
