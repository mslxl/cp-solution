#include<iostream>
int main()
{
	int i, j, k, n = 5;
	char c;
	std::cin >> c;
	n /= 2;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n - 1 - i; j++)
			std::cout << ' ';
		for (k = 0; k <= 2 * i; k++)
			std::cout << c;
		std::cout << std::endl;
	}
	for (i = 0; i <= n - 1; i++)
	{
		for (j = 0; j <= i; j++)
			std::cout << ' ';
		for (k = 0; k <= (n - 1) * 2 - 2 * i; k++)
			std::cout << c;
		std::cout << std::endl;
	}
	return 0;
}
