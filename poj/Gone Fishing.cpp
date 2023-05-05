// Problem: Gone Fishing
// Contest: Virtual Judge - POJ
// URL: https://vjudge.net/problem/POJ-1042
// Memory Limit: 32 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 30;

struct Fish {
	int f, d, t, p;
	bool operator<(const Fish &a1)const {
		if (f == a1.f) return p > a1.p;
		return f < a1.f;
	}
} fish[maxn];

int consume_time[maxn], gain[maxn];
int T, n, h;

int main() {
	while (std::cin >> n && n) {
		memset(gain, 0, sizeof(gain));
		
		scanf("%d", &h);
		for (int i = 0; i < n; ++i)
		  scanf("%d", &fish[i].f);
		for (int i = 0; i < n; ++i)
		  scanf("%d", &fish[i].d);
		for (int i = 0; i < n - 1; i++)
		  scanf("%d", &fish[i].t);
		for (int i = 0; i < n; i++)
		  fish[i].p = i;
		int res = 0;
		for (int i = 0; i < n; i++) {
			int times = h * 60;
			memset(consume_time, 0, sizeof(consume_time));
			priority_queue<Fish> q1;
			int ans = 0;

			for (int j = 0; j < i; j++)
				times -= fish[j].t * 5;

			for (int j = 0; j <= i; ++j)
				q1.push(fish[j]);

			while (times >= 5 && !q1.empty()) {
				Fish z = q1.top();
				q1.pop();
				times -= 5;
				consume_time[z.p]++;
				ans += z.f;
				z.f = z.f - z.d;
				if (z.f < 0)z.f = 0;
				q1.push(z);
			}
			if (ans > res) {
				res = ans;
				for (int k = 0; k < n; k++) {
					gain[k] = consume_time[k];
				}
			}

			else if (ans == res) {
				int judge = 0;
				for (int k = 0; k < n; k++) {
					if (consume_time[k] > gain[k]) {
						judge = 1;
						break;
					} else if (consume_time[k] < gain[k])break;
					else continue;
				}

				if (judge) {
					for (int k = 0; k < n; k++) {
						gain[k] = consume_time[k];
					}
				}
			}

		}
		if (T++)printf("\n");
		for (int i = 0; i < n - 1; i++) {
			printf("%d, ", gain[i] * 5);
		}
		printf("%d\n", gain[n - 1] * 5);
		printf("Number of fish expected: %d\n", res);
	}
	return 0;
}