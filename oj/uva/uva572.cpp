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

char map[100][100];
bool vis[100][100];
int h, w;
int num = 0;

bool dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= w || y >= h)
        return false;
    else if (map[y][x] == '*' || vis[y][x])
        return false;
    else if (map[y][x] == '@') {
        vis[y][x] = true;
        dfs(x - 1, y - 1);
        dfs(x, y - 1);
        dfs(x + 1, y - 1);
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x - 1, y + 1);
        dfs(x, y + 1);
        dfs(x + 1, y + 1);
        return true;
    } else {
        return false;
    }
}

int main(int argc, char const* argv[]) {
    while (scanf("%d%d", &h, &w) != EOF && h && w) {
        memset(vis, false, sizeof(vis));
        num = 0;
        _for(y, 0, h) { scanf("%s", map[y]); }
        _for(x, 0, w) {
            _for(y, 0, h) {
                if (dfs(x, y)) {
                    num++;
                }
            }
        }

        printf("%d\n", num);
    }

    return 0;
}