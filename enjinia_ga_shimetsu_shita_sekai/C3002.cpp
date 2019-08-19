// 機械の総合病院
// 机器化综合病院

#include <iostream>
#include <string>
#include <cstring>

#define INVALID_END std::cout << "Invalid";return 0;
#define VALID_END std::cout << "Valid";return 0;


int main() {
	// 自分の得意な言語で
	// Let's チャレンジ！！

	char t[30];
	bool hasAlph, hasNum;
	int appearTimes = 1;

	std::cin >> t;
	if (strlen(t) < 6) {
		INVALID_END
	}
	for (auto i = 0; i < strlen(t); i++)
	{
		if (isupper(t[i])) {
			t[i] = tolower(t[i]);
		}
		if (isalpha(t[i])) {
			hasAlph = true;
		}
		if (isdigit(t[i])) {
			hasNum = true;
		}
		if (i != 0 && t[i] == t[i - 1]) {
			appearTimes++;
			if (appearTimes >= 3) {
				INVALID_END
			}
		}
		else {
			appearTimes = 1;
		}
	}
	if (hasNum && hasAlph) {
		VALID_END
	}
	INVALID_END
}