#include<bits/stdc++.h>

double H(int one, int zero){
	double ans = 0;
	for(int i = 0 ; i < one; i++){
		double p = (1.0 * one) / (one + zero);
		ans +=( -p ) * std::log2(p);
	}
	for(int i = 0 ; i < zero; i++){
		double p = (1.0 * zero) / (one + zero);
		ans +=( -p ) * std::log2(p);
	}
	return ans;
}

int main(){
	std::cout << "100 -> " << H(1,2)  << std::endl;
	std::ofstream os("B.txt");
	const int length = 23333333;
	for(int one = 0; one <= length; one++){
		int zero = length - one;
		
		if(std::abs(H(one, zero)-11625907.5798) < 0.00001){
			std::cout << "one: " << one << "\n" << "zero: " << zero << "\n";
			os <<  "one: " << one << "\n" << "zero: " << zero << std::endl;
		}
	}
	return 0;
}
