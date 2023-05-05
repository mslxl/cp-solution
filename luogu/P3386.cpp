#include <algorithm>
#include <iostream>

const int N = 510, M = 100010;

int n, m, c;

struct Edge{
  int to, next;
}e[M];
int head[N], eid=0;

int match[N];
bool st[N];

void add(int a, int b) {
	e[++eid].to = b;
	e[eid].next = head[a];
	head[a] = eid;
}

bool find(int u) {
	for (int i = head[u]; i!= 0; i = e[i].next) {
		const int v = e[i].to;
		if (!st[v]) {
			st[v] = true;
			if (!match[v] || find(match[v])) {
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

int main() {
  std::cin >> n >> m >> c;

	while (c--) {
		int a, b;
		std::cin >> a >> b;
		add(a, b);
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
	  std::fill(st, st + N, false);
		if (find(i)) res++;
	}

  std::cout << res;
	
	return 0;
}