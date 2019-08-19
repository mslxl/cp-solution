// 隔離された街のゲート
// 被隔离的街道大门
#include <iostream>

int main() {
	// 自分の得意な言語で
	// Let's チャレンジ！！
	int H, W, N, x = 0, y = 0;
	char m;
	std::cin >> H >> W >> N;
	for (auto i = 0; i < N; i++)
	{
		std::cin >> m;
		if (m == 'D') {
			y--;
		}
		else if (m == 'U') {
			y++;
		}
		else if (m == 'L') {
			x--;
		}
		else if (m == 'R') {
			x++;
		}
		if (x < 0 || y < 0 || x >= W || y >= H) {
			std::cout << "invalid";
			return 0;
		}
	}
	std::cout << "valid";

	return 0;
}