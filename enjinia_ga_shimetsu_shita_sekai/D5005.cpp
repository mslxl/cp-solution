//�������������ʤ��y��
//�޷���������
#include<iostream>
int main() {
	// �Է֤ε�������Z��
	// Let's �����󥸣���
	int n, w,r;
	std::cin >> n >> w;
	r = n - w;
	if (r < 0) {
		std::cout << "error";
	}
	else {
		std::cout << r;
	}
	return 0;
}