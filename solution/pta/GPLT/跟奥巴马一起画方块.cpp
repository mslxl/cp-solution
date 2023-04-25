#include<bits/stdc++.h>

// 柯里化整个活 
std::function<std::string(int)> rpstr(char c){
	return [c](int rep) -> std::string {
		return std::string(rep,c);
	};
}
int main(){
	int times;
	char c;
	std::cin >> times >> c;
	auto prod = rpstr(c);
	for(int i = 0; i < std::round(1.0 * times / 2);i++){
		std::cout << prod(times) << std::endl;
	}
	return 0;
}

