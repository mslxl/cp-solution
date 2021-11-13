#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
typedef long long ll;
typedef unsigned long long ull;
char image[200 * 8][50 * 8];
bool vis[200 * 8][50 * 8];
int H, W;

bool fill_black(int x, int y) {
    if (x < 0 || y < 0 || x >= W * 8 || y >= H * 8)
        return false;
    if (vis[y][x] || image[y][x] != '0')
        return false;
    if (image[y][x] == '0') {
        vis[y][x] = true;

        fill_black(x + 1, y);
        fill_black(x - 1, y);
        fill_black(x, y + 1);
        fill_black(x, y - 1);

        return true;
    }
    return false;
}

int[8] hex2bin(char c) {
    char x[17][5] = {"0000", "0001", "0010", "0011", "0100", "0101",
                     "0110", "0111", "1000", "1001", "1010", "1011",
                     "1100", "1101", "1110", "1111", "xxxx"};
    int n = 16;
    if (c >= 'a' && c <= 'f')
        n = c - 'a' + 10;
    if (c >= 'A' && c <= 'F')
        n = c - 'A' + 10;
    if (c >= '0' && c <= '9')
        n = c - '0';

    int ret[4];
    _for(idx, 0, 4) { ret[idx] = x[n][idx] - '0'; }
    return ret;
}

int solve_blank() {
    int T = 0;
    _for(x, 0, W) {
        _for(y, 0, H) {
            if (fill_black(x, y)) {
                T++;
            }
        }
    }
    return T;
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    char solu[50];
    solu[2] = 'A';
    solu[4] = 'J';
    solu[6] = 'D';
    solu[5] = 'S';
    solu[0] = 'W';
    solu[3] = 'K';

    int kase = 0;
    while (std::cin >> H >> W && H != 0 && W != 0) {
        memset(vis, false, sizeof(vis));

        _for(y, 0, H) { scanf("%s", image[y]); }
        int N = solve_blank();
        printf("Case %d: %d", ++kase, solu[N]);
    }

    return 0;
}