// 有名なプールサイド 
// 有名的水边

// 有问题，过不了测试
// 但是能通过

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int bk[666][666];
struct node
{
	int h, w, x, y, id;
}num[666];
bool cmp(node a, node b)
{
	return a.h * a.w > b.h * b.w;
}
int main()
{
	// 自分の得意な言語で
	// Let's チャレンジ！！
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, t, p = 0;
	cin >> n >> m >> t;
	int now = n * m, minx = 1, miny = 1;
	for (int i = 1; i <= t; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > 0 && a <= n && b > 0 && b <= m) {
			num[p++] = node{ a,b,c,d,i };
		}

	}
	sort(num, num + p, cmp);
	int maxx = 0;
	maxx += num[0].h;
	int maxy = 0;
	maxy += num[0].w;
	if (num[0].x == 1)
	{
		maxx++; minx++;
		for (int j = minx; j <= maxx; j++) {
			for (int k = miny; k <= maxy; k++) { bk[j][k] = num[0].id; }

		}

	}
	else if (num[0].x == num[0].h)
	{
		for (int j = minx; j <= maxx; j++) {
			for (int k = miny; k <= maxy; k++) {
				bk[j][k] = num[0].id;
			}
		}


	}
	else if (num[0].y == 1)
	{
		miny++; maxy++;
		for (int j = minx; j <= maxx; j++) {
			for (int k = miny; k <= maxy; k++) { bk[j][k] = num[0].id; }
		}

	}
	else if (num[0].y == num[0].w)
	{
		for (int j = minx; j <= maxx; j++) {
			for (int k = miny; k <= maxy; k++) {
				bk[j][k] = num[0].id;
			}
		}


	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << bk[i][j];
			if (j < m) {
				cout << ' ';
			}

		}
		cout << endl;
	}
}