#include<iostream>
int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	int da = a, db = b, dc = c;
	while (true) {
		if (da == db && db == dc) {
			std::cout << da;
			break;
		}
		if (da <= db && da <= dc) {
			da += a;
		}
		else if (db <= da && db <= dc) {
			db += b;
		}
		else if (dc <= da && dc <= db) {
			dc += c;
		}
	}
	return 0;
}