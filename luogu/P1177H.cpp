#include<iostream>
#include<algorithm>
int main() {
	std::ios::sync_with_stdio(false);
	int N;
	std::cin >> N;
	auto a = new int[N];
	for (auto i = 0; i < N; i++)
	{
		std::cin >> *(a + i);
	}
	std::sort(a, a + N);
	for (auto i = 0; i < N; i++)
	{
		std::cout << *(a + i) << ' ';
	}
}