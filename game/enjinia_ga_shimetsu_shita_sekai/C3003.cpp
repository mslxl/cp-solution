//ѧ�٤ʤ�ѧУ
//û��ѧ����ѧУ

#include <iostream>

bool win(char a, char b) {
	return (a == 'g' && b == 'c') || (a == 'c' && b == 'p') || (a == 'p' && b == 'g');
}

int main() {
	// �Է֤ε�������Z��
	// Let's �����󥸣���
	int N, wa = 0, wb = 0;
	char a, b;
	std::cin >> N;
	for (auto i = 0; i < N; i++)
	{
		std::cin >> a >> b;
		if (win(a, b)) {
			++wa;
		}
		else {
			++wb;
		}
	}
	std::cout << wa << std::endl << wb;


	return 0;
}