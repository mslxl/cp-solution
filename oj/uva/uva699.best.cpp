#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
typedef long long ll;
typedef unsigned long long ull;
std::set<int> ids;
std::map<int, int> val;
int pos = 0;
void read() {
    int v;
    std::cin >> v;
    if (v == -1)
        return;
    if (!ids.count(pos)) {
        ids.insert(pos);
        val[pos] = 0;
    }
    val[pos] += v;
    pos--;
    read();
    pos += 2;
    read();
    pos--;
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int T = 1;
    while (true) {
        ids.clear();
        val.clear();
        pos = 0;
        read();
        if (ids.size() == 0) {
            break;
        }
        int idx = 1;
        std::cout << "Case " << T++ << ':' << std::endl;
        for (auto item : ids) {
            std::cout << val[item];
            if (idx++ != ids.size()) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl << std::endl;
    }

    return 0;
}