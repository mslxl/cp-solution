#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = s; i < e; i++)
typedef long long ll;
bool is_prime(int n){
	if(n <= 1) return false;
	int max = sqrt(n) + 1;
	for(int i = 2; i < max; i++){
		if(n % i == 0) return false;
	}
	return true;
}
int main(){
	int L, K;
	std::string line;
	std::cin >> L >> K;
	std::cin >> line;
	for(int i = 0; i + K - 1 < line.size(); i++){
		const auto& number = line.substr(i,K);
		int n = std::stoi(number.c_str());
		if(is_prime(n)){
			std::cout << number;
			return 0;
		}
	}
	std::cout << 404;
	return 0;
}
