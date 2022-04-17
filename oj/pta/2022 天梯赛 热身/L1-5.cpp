#include<bits/stdc++.h>

int sum_digit(int num){
	//std::cout << num << "->";
	int sum = 0;
	while(num > 0){
		sum += num % 10;
		num /= 10;
	}
	//std::cout << "Sum " << sum << std::endl;
	return sum;
}

int main(){
	int N;
	std::cin >> N;
	while(N--){
		int num;
		std::cin >> num;
		int init = sum_digit(num * 2);
		bool valid = true;
		for(int i = 3; i <= 9; i++){
			if(sum_digit(num * i) != init){
				valid = false;
				break;
			}
		}
		if(valid){
			std::cout << init;
		}else{
			std::cout << "NO";
		}
		if(N != 0) std::cout << std::endl;
	}
}
