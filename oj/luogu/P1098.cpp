#include <iostream>
#include <cstring>

void output(char c, int t) {
	for (auto i = 0; i < t; i++)
	{
		std::cout << c;
	}
}
// TODO #8 WA
int main() {
	int p1, p2, p3;
	std::cin >> p1 >> p2 >> p3;
	char* c = new char[101];
	auto begin = c;
	std::memset(c, '\0', sizeof(char) * 101);
	std::cin >> c;

	do {
		if (*c != '-') {
			std::cout << *c;

		} else {
			if (*(c + 1) == '-' || *(c - 1) == '-' || c == begin || *(c+1) == '\0') {
				std::cout << '-';
				continue;
			}
			int step = 1;
			char s = tolower(*(c - 1));
			char d = tolower(*(c + 1));
			if (p3 != 1) {
				step = -1;
				std::swap(s, d);
			}
			if ((s + step - d) * step <= 0 && ((isdigit(s) == isdigit(d)))) {
				while (((s += step) - d) * step < 0) {
					output((p1 == 3) ? '*' : (p1 == 1 ? tolower(s) : toupper(s)), p2);
				}
			}
			else {
				std::cout << '-';
			}
		}
	} while (*(++c) != '\0');

	return 0;
}