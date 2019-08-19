#include<iostream>

int main() {
	int N;
	std::cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i];
	}

	return 0;
}
