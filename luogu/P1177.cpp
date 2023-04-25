#include<iostream>

// 还是 TLE
void quickSort(int* begin, int* end) {

	auto left = begin, right = end - 1;

	if (left >= right) {
		return;
	}
	int tmp = *left; // 基准数
	while (left != right) {
		while (*(right) >= tmp && left < right) {
			right--;
		}
		while (*(left) <= tmp && left < right) {
			left++;
		}
		if (left < right) {
			auto t = *left;
			*left = *right;
			*right = t;
		}
	}
	*begin = *left;
	*left = tmp;
	quickSort(begin, left + 1);
	quickSort(left + 1, end);
	return ;
}

int main() {
	// 高性能
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;
	int* arr = new int[N];
	for (auto i = 0; i < N; ++i)
	{
		std::cin >> arr[i];
	}
	quickSort(arr, arr + N);
	for (auto i = 0; i < N; i++)
	{
		std::cout << *(arr + i) << ' ';
	}
	return 0;
}
