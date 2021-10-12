#include<iostream>
int main() {
	for (auto i = 0; ; i++)
	{
		int k;
		std::cin >> k;
		if (i == 2) {
			std::cout << k;
			return 0;
		}
	}
	
}