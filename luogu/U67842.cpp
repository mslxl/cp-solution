#include<iostream>
int main() {
	int s = 8765;
	std::cout << s / 60 / 60 << 'h'
		<< s / 60 % 60 << 'm'
		<< s % 60 << 's';
	return 0;
}