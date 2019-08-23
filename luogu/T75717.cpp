#include <iostream>
int main() {
	int k;
	std::cin >> k;
	while (k > 0) {
		std::cout << k % 10;
		k /= 10;
	}
	return 0;
}