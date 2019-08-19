//錆びついた電波塔
//生锈的无线电塔

#include<iostream>
int main() {
	// 自分の得意な言語で
	// Let's チャレンジ！！
	int n,d,c=0;
	std::cin >> n;
	
	for (auto i = 0; i < n; ++i)
	{
		std::cin >> d;
		if (d > 5) {
			++c;
		}
	}
	std::cout << c;
	return 0;
}