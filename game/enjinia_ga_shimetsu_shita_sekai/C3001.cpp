// �Ĥ���Ƥ�����å�
// �������̵�

#include <iostream>
#include <cstring>
#include <string>

void fp(int N, int num) {
	auto i = 0,t = num;
	while ((t /= 10) > 0) {
		++i;
	}
	for (auto j = 1; j < N - i; j++)
	{
		std::cout << '0';
	}
	std::cout << num << std::endl;
}

int main() {
	// �Է֤ε�������Z��
	// Let's �����󥸣���
	int N, A, B;
	std::cin >> N >> A >> B;

	for (auto i = A; i <= B; i++)
	{
		fp(N, i);
	}
	return 0;
}