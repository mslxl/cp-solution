#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
int n, m;

int atk_a[8], atk_b[8];

struct battle {
	ll a[8] = {0};
	ll b[8] = {0};
};

ll alice_win = 0, bob_win = 0, eq_win = 0;

// 0 -> alice
// 1 -> bob
// 2 -> eq
// 3 -> to be continue
int judge(const battle& b) {
	int neg_a = 0, neg_b = 0;
	for (int i = 0; i < n; i++) {
		if (b.a[i] <= 0) neg_a++;
	}
	for (int i = 0; i < m; i++) {
		if (b.b[i] <= 0) neg_b++;
	}
	if (neg_a == n && neg_b == m) {
		return 2;
	} else if (neg_a == n) {
		return 0;
	} else if (neg_b == m) {
		return 1;
	} else {
		return 3;
	}
}

std::vector<battle> attack(const battle& b, char oct, int idx) {
	std::vector<battle> bts;

	if (oct == 'A') {
		if (b.a[idx] <= 0) return std::vector<battle>();

		for (int being = 0; being < 7; being++) {
			if (b.b[being] <= 0) continue;
			battle newbat(b);
			newbat.b[being] -= atk_a[idx];
			newbat.a[idx] -= atk_b[being];
			bts.push_back(newbat);
		}
		return bts;
	} else if (oct == 'B') {
		if (b.b[idx] <= 0) return std::vector<battle>();
		for (int being = 0; being < 7; being++) {
			if (b.a[being] <= 0) continue;
			battle newbat(b);
			newbat.a[being] -= atk_b[idx];
			newbat.b[idx] -= atk_a[being];
		}
		return bts;
	} else {
		std::abort();
	}
}

void aturn(std::vector<battle> bts, char start_op, int idx_a = 0, int idx_b = 0) {
	
	std::vector<battle> res;
	for (const auto& b : bts) {
	
		
		char oct = start_op;

		std::vector<battle> all = attack(b, oct, idx_a);

		for (std::vector<battle>::iterator iter = all.begin(); iter != all.end(); iter++) {
			int result = judge(*iter);
			if (result == 0) {
				alice_win++;
				iter = all.erase(iter);
			} else if (result == 1) {
				bob_win++;
				iter = all.erase(iter);
			} else if (result == 2) {
				eq_win++;
				iter = all.erase(iter);
			}
		}

		if (oct == 'A') {
			oct = 'B';
			idx_a++;
		} else if (oct == 'B') {
			oct = 'A';
			idx_b++;
		}
		
		aturn(all, oct, idx_a, idx_b);
	}
}




int main() {
	battle begin;
	std::cin >> n >> m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> begin.a[i];
		atk_a[i] = begin.a[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> begin.b[i];
		atk_b[i] = begin.b[i];
	}
}
