#include<bits/stdc++.h>
#define DEBUG

#ifdef DEBUG
#define debug if(1)
#else
#define debug if(0)
#endif


using ll = long long;
using ld = long double;
struct player {
	ll hp;
	ll atk;
};

struct battle {
	std::vector<player> alice;
	std::vector<player> bob;
	char atker = 'U';
	int depth = 0;
};

template<typename T>
void rotate(std::vector<T> & seq) {
	if (seq.empty()) return;
	T i = seq[0];
	seq.erase(seq.begin());
	seq.push_back(i);
}

ll alice_win = 0, bob_win = 0, eq_win = 0;

void attack(const battle& be) {
	debug std::cout << "a";
	std::vector<battle> res;
	if (be.atker == 'A') {
		const auto& atker = be.alice[0];
		assert(atker.hp > 0);
		debug std::cout << "b";
		for (int bid = 0; bid < be.bob.size(); bid++) {
			battle b(be);
			b.bob[bid].hp -= atker.atk;
			b.alice[0].hp -= b.bob[bid].atk;
			if (b.alice[0].hp <= 0) {
				b.alice.erase(b.alice.begin());
			}else{
				rotate(b.alice);
			}
			debug std::cout << "c";
			if (b.bob[bid].hp <= 0) {
				b.bob.erase(b.bob.begin() + bid);
				bid--;
				debug std::cout << "d";
				if(b.bob.empty()) {
					res.push_back(b);
					debug std::cout << "e";
					bid = std::numeric_limits<int>::max();
				}
			}
			debug std::cout << "f";
			b.depth++;
			b.atker = 'B';
			res.push_back(b);
		}
	} else if (be.atker == 'B') {
		const auto& atker = be.bob[0];
		assert(atker.hp > 0);
		for (int bid = 0; bid < be.alice.size(); bid++) {
			battle b(be);
			b.alice[bid].hp -= atker.atk;
			b.bob[0].hp -= b.alice[bid].atk;
			if (b.bob[0].hp <= 0) {
				b.bob.erase(b.bob.begin());
			}else{
				rotate(b.bob);
			}
			if (b.alice[bid].hp <= 0) {
				b.alice.erase(b.alice.begin() + bid);
				bid--;
				if(b.alice.empty()) {
					res.push_back(b);
					bid = std::numeric_limits<int>::max();
				}
			}
			

			b.depth++;
			b.atker = 'A';
			res.push_back(b);
		}
	} else {
		std::abort();
	}

	for (battle &bbt : res ) {
		if (bbt.alice.empty() && bbt.bob.empty()) {
			debug std::cerr << "EQ when depth " << bbt.depth << std::endl;
			eq_win++;
			continue;
		} else if (bbt.alice.empty()) {
			debug std::cerr << "BOB when depth " << bbt.depth << std::endl;
			bob_win++;
			continue;
		} else if (bbt.bob.empty()) {
			debug std::cerr << "ALICE when depth " << bbt.depth << std::endl;
			alice_win++;
			continue;
		} else {
			debug std::cerr << "Continue after depth " << bbt.depth << std::endl;
			attack(bbt);
		}
	}
}




int main() {
	
	int n, m;
	std::cin >> n >> m;

	std::vector<player> alice;
	std::vector<player> bob;
	for (int i = 0; i < n; i++) {
		ll c;
		std::cin >> c;
		alice.push_back(player{c,c});
	}
	for (int i = 0; i < m; i++) {
		ll c;
		std::cin >> c;
		bob.push_back(player{c,c});
	}

	battle batA{
		alice,
		bob,
		'A'
	};
	attack(batA);
	
	battle batB{
		alice,
		bob,
		'B'
	};
	attack(batB);
	
	
	debug std::cerr << alice_win << "/" << bob_win << "/" << eq_win << std::endl;
	

	ll tot = alice_win + bob_win + eq_win;
	ld a = ld(alice_win) / tot;
	ld b = ld(bob_win) / tot;
	ld e = ld(eq_win) / tot;
	std::cout << a << "\n" << b << "\n" << e;

}
