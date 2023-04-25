//アンドロイドの生産工場
//Android 工厂
#include <iostream>
int main() {
	// 自分の得意な言語で
	// Let's チャレンジ！！
	char * S = new char[100];
	std::cin >> S;
	for (auto i = 0; *(S + i * 2) != '\0'; ++i) {
		std::cout << *(S + i * 2);
	}
	
	return 0;
}