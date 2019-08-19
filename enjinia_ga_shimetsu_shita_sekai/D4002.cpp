//荒れ果てたオフィス
//荒凉的办公室

#include <iostream>
int main() {
	// 自分の得意な言語で
	// Let's チャレンジ！！
	int n,level;
	char S[100];
	std::cin >> n;
	for (auto i = 0; i < n; i++)
	{
		std::cin >> S >> level;
		if (level == 3) {
			std::cout << S << std::endl;
		}
	}
	
	return 0;
}