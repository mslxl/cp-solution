#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
#define _br() std::cout << std::endl;
typedef long long ll;
typedef unsigned long long ull;

void mapDo(std::map<int, int>& sch, int pos, int offset) {
    if (!sch.count(pos))
        sch[pos] == 0;
    sch[pos] += offset;
}
int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int n;
    while (std::cin >> n && n != 0) {
        std::map<int, int> sch;
        _for(idx, 0, n) {
            int A, B;
            std::cin >> A >> B;
            mapDo(sch, A, -1);
            mapDo(sch, B, +1);
        }
        bool valid = true;
        for (auto item : sch) {
            if (item.second != 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            std::cout << "YES";
        } else {
            std::cout << "NO";
        }
        std::cout << std::endl;
    }

    return 0;
}