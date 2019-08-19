// 砂漠の公園
// 沙漠公园

#include <iostream>

struct Team
{
	int num;
	int win = 0;
	int lost = 0;
	int tie = 0;
};

int main() {
	// 自分の得意な言語で
	// Let's チャレンジ！！
	int N;
	std::cin >> N;
	auto teams = new Team[N];
	char re;
	for (auto i = 0; i < N; i++)
	{
		teams[i].num = i + 1;
		for (auto j = 0; j < N; j++)
		{
			std::cin >> re;
			if (i == j) {
				continue;
			}
			if (re == 'W') {
				teams[i].win++;
				teams[j].lost++;
			}
			else if (re == 'L') {
				teams[j].win++;
				teams[i].lost++;
			}
			else if (re == 'D') {
				teams[j].tie++;
				teams[i].tie++;
			}
		}
	}
	Team* win;
	int score = 0;
	for (auto i = 0; i < N; i++)
	{
		auto e = &teams[i];
		auto s = e->win * 2 + e->tie;
		if (s > score) {
			win = e;
			score = s;
		}
	}
	std::cout << win->num << ' ' << score / 2 << ' ' << win->win / 2 << ' '
		<< win->tie / 2 << ' ' << win->lost / 2;
	return 0;
}