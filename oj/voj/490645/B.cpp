#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = s; i < e; i++)

const int maxn = 1e5 + 17;

int a[maxn], b[maxn];
std::map<int, int> bucket;

void solve() {
	bucket.clear();
	int n;
	std::cin >> n;
	rep(i, 0, n) std::cin >> a[i];
	rep(i, 0, n) std::cin >> b[i];
	rep(i, 0, n) {
		int minus = b[i] - a[i];
		bucket[minus]++;
	}

	int max = 0, max_idx;
	for (auto& entry : bucket) {
		int i = entry.first;
		if (bucket[i] > max) {
			max = bucket[i];
			max_idx = i;
		}
	}
	std::cout << max << std::endl;
}

int main() {
	int N;
	std::cin >> N;
	while(N--) {
		solve();
	}
}
