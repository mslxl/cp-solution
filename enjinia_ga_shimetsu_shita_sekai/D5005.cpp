//お金が引き出せない銀行
//无法提款的银行
#include<iostream>
int main() {
	// 自分の得意な言語で
	// Let's チャレンジ！！
	int n, w,r;
	std::cin >> n >> w;
	r = n - w;
	if (r < 0) {
		std::cout << "error";
	}
	else {
		std::cout << r;
	}
	return 0;
}