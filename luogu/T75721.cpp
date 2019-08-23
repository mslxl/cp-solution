#include<iostream>
int main() {
	int w = 5, h = 3;
	char c;
	std::cin >> c;
	for (auto i = 1; i <= h; i++)
	{
		for (auto j = 1; j <= w; j++)
		{
			if (j == w / 2 + 1) {
				std::cout << c;
				continue;
			}
			auto d = (i - 1) * 2;
			if (abs(j - (w / 2 + 1)) < d) {
				std::cout << c;
				continue;
			}
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}