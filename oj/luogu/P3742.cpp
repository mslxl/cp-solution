#include<iostream>
#include<string>
#include<cstring>
int main()
{
	int n;
	std::string x, z;
	std::cin >> n;
	std::cin >> x >> z;
	for (int i = 0; i < n; i++)
	{
		if (x[i] < z[i])
		{
			std::cout << -1;
			return 0;

		}
	}
	std::cout << z;
}