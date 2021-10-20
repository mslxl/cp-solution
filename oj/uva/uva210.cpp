#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
#define _br() std::cout << std::endl;

struct Stat {
    int prog_id;
    int op;
    std::string target;
    int v;
};

typedef std::deque<Stat> Prog;
bool locked = false;
std::map<std::string, int> mem;
std::deque<Prog> prog;
std::queue<Prog> block_prog;

typedef long long ll;
typedef unsigned long long ull;

std::string to_lower(const std::string& str) {
    std::string txt(str);
    for (auto& c : txt) {
        c = tolower(c);
    }
    return txt;
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int T;
    int n, t1, t2, t3, t4, t5, Q;
    std::cin >> T;
    while (T--) {
        prog.clear();
        block_prog = std::queue<Prog>();
        mem.clear();
        locked = false;

        std::cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q;
        std::string line;
        std::deque<Stat> que;

        for (int idx = 1; idx <= n;) {
            std::cin >> line;
            if (to_lower(line) == "print") {
                std::string target;
                std::cin >> target;
                Stat st{idx, 1, target};
                que.push_back(st);
            } else if (to_lower(line) == "lock") {
                Stat st{idx, 2};
                que.push_back(st);
            } else if (to_lower(line) == "unlock") {
                Stat st{idx, 3};
                que.push_back(st);
            } else if (to_lower(line) == "end") {
                Stat st{idx, 5};
                que.push_back(st);
                prog.push_front(que);
                que = std::deque<Stat>();
                idx++;
            } else {
                std::string& target = line;
                int value;
                std::cin.get();
                std::cin.get();
                // getchar();
                std::cin >> value;
                Stat st{idx, 4, target, value};
                que.push_back(st);
            }
        }

        while (!prog.empty()) {
            int used_Q = Q;
            auto pg = prog.back();
            bool blocked = false;
            prog.pop_back();
            while (used_Q > 0 && !pg.empty()) {
                auto stat = pg.front();
                if (stat.op == 1) {
                    // Print
                    pg.pop_front();
                    used_Q -= t2;
                    if (!mem.count(stat.target)) {
                        mem[stat.target] = 0;
                    }
                    std::cout << stat.prog_id << ": " << mem[stat.target]
                              << std::endl;
                } else if (stat.op == 2) {
                    // Lock
                    if (locked) {
                        block_prog.push(pg);
                        blocked = true;
                        break;
                    } else {
                        pg.pop_front();
                        used_Q -= t3;
                        locked = true;
                    }
                } else if (stat.op == 3) {
                    // Unlock
                    pg.pop_front();
                    used_Q -= t4;
                    locked = false;
                    if (!block_prog.empty()) {
                        prog.push_back(block_prog.front());
                        block_prog.pop();
                    }
                    // while (!block_prog.empty()) {
                    //     prog.push_front(block_prog.front());
                    //     block_prog.pop();
                    // }
                } else if (stat.op == 4) {
                    // Assign
                    pg.pop_front();
                    used_Q -= t1;
                    mem[stat.target] = stat.v;
                } else if (stat.op == 5) {
                    // END
                    pg.pop_front();
                    used_Q -= t5;
                }
            }
            if (!pg.empty() && !blocked) {
                prog.push_front(pg);
            }
        }
        if (T != 0) {
            std::cout << std::endl;
        }
    }

    return 0;
}