#include <iostream>
#include <cstring>
#include <cmath>



template<typename T1, typename T2>
constexpr auto min(T1 x, T2 y) { return x < y ? x : y; }


bool strcompare(const char* a, const char* b) {
	int len = strlen(a);
	bool eq = true;
	for (auto i = 0; i < len; i++)
	{
		if (*(a + i) != *(b + i)) {
			eq = false;
		}
	}
	return eq;
}

int main(void) {
	// 自分の得意な言語で
	// Let's チャレンジ！！
	int N;
	std::cin >> N;
	char* l = new char[100 * N];
	char* p = new char[100];
	std::memset(l, '\0', sizeof(l));
	for (auto i = 0; i < N; i++)
	{
		std::cin >> p;

		char* lastChar = l + strlen(l) - 1;
		int mlen = min(strlen(l), strlen(p));
		bool hasRepeat = false;
		for (auto index = mlen - 1; index >= 0; index--)
		{
			if (strcompare(lastChar - index, p)) {
				strcpy(lastChar, p + index);
				hasRepeat = true;
				break;
			}
		}
		if (!hasRepeat) {
			strcpy(lastChar + 1, p);
		}
	}
	std::cout << l;
	delete[] l;
	delete[] p;
	return 0;
}