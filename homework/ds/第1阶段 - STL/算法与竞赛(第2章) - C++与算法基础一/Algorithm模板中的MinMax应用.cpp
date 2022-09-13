#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>

template<typename T>
void solve_type(){
	T a,b;
	std::cin >> a >> b;
	std::cout << "min(" << a << "," << b << ")==" << std::min(a,b) << std::endl;
	std::cout << "max(" << a << "," << b << ")==" << std::max(a,b) << std::endl;
}


int main(){
	solve_type<int>();
	solve_type<float>();
	solve_type<char>();
	solve_type<std::string>();
	return 0;
}
