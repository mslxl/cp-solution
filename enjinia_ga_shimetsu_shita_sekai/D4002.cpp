//�Ĥ���Ƥ����ե���
//�����İ칫��

#include <iostream>
int main() {
	// �Է֤ε�������Z��
	// Let's �����󥸣���
	int n,level;
	char S[100];
	std::cin >> n;
	for (auto i = 0; i < n; i++)
	{
		std::cin >> S >> level;
		if (level == 3) {
			std::cout << S << std::endl;
		}
	}
	
	return 0;
}