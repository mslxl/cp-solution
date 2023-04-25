#include<bits/stdc++.h>

long double Hf(int one, int zero){
	long double ans = 0;
	for(int i = 0 ; i < one; i++){
		long double p = (1.0 * one) / (one + zero);
		ans +=( -p ) * std::log2(p);
	}
	for(int i = 0 ; i < zero; i++){
		long double p = (1.0 * zero) / (one + zero);
		ans +=( -p ) * std::log2(p);
	}
	return ans;
}
// 11027421  12305912
int main(){
	std::cout << "100 -> " << Hf(1,2)  << std::endl;

	const int length = 23333333;
	int one = 0;
	while(true){
		int zero = length - one;
		
		long double H = Hf(one, zero);
		printf("H(%d, %d) = %.4lf \t(offset = %.5lf)\n", one, zero, double(H), double(H - 11625907.5798));
	
		if(std::abs(H-11625907.5798) < 0.00001){
			std::cout << "success" << std::endl;
		}
		
		int offset;
		std::cin >> offset;
		one += offset;
	}

	return 0;
}
