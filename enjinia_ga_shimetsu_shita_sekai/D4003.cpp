//����ɥ��ɤ����b����
//Android ����
#include <iostream>
int main() {
	// �Է֤ε�������Z��
	// Let's �����󥸣���
	char * S = new char[100];
	std::cin >> S;
	for (auto i = 0; *(S + i * 2) != '\0'; ++i) {
		std::cout << *(S + i * 2);
	}
	
	return 0;
}