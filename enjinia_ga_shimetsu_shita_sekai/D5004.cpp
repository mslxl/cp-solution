//䝤ӤĤ���늲���
//��������ߵ���

#include<iostream>
int main() {
	// �Է֤ε�������Z��
	// Let's �����󥸣���
	int n,d,c=0;
	std::cin >> n;
	
	for (auto i = 0; i < n; ++i)
	{
		std::cin >> d;
		if (d > 5) {
			++c;
		}
	}
	std::cout << c;
	return 0;
}