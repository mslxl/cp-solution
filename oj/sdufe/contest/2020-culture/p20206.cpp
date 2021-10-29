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
int T, n, m;
int num_c;
int pos(int r, int c) {
    int filp = c % 2 == 0;
    int idx = (c - 1) * n;
    idx += (filp ? n - r + 1 : r);
    return idx;
}
int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        num_c = ceil(1.0 * m / n);
        _rep(r, 1, n) {
            _rep(c, 1, num_c) {
                int idx = pos(r, c);
                if (idx > m) {
                    break;
                }
                std::cout << idx;
                if (pos(r, c + 1) <= m) {
                    std::cout << ' ';
                }
            }
            std::cout << std::endl;
        }
    }
    return 0;
}