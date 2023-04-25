#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 100 + 5;
struct Building {
    int id;
    double x, y, w, d, h;
    bool operator<(const Building& rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
} b[maxn];

int n;
double x[maxn * 2];

bool cover(int i, double mx) {
    return b[i].x <= mx && b[i].x + b[i].w >= mx;
}

bool visible(int i, double mx) {
    if (!cover(i, mx))
        return false;
    _for(k, 0, n) if (b[k].y < b[i].y && b[k].h >= b[i].h &&
                      cover(k, mx)) return false;
    return true;
}

int main(int argc, char const* argv[]) {
    int kase = 0;
    while (std::cin >> n && n) {
        _for(i, 0, n) {
            Building& obj = b[i];
            std::cin >> obj.x >> obj.y >> obj.w >> obj.d >> obj.h;
            x[i * 2] = obj.x;
            x[i * 2 + 1] = obj.x + obj.w;
            obj.id = i + 1;
        }
        std::sort(b, b + n);
        std::sort(x, x + n * 2);
        int m = std::unique(x, x + n * 2) - x;
        if (kase++)
            std::cout << std::endl;
        printf(
            "For map #%d, the visible buildings are numbered as follows:\n%d",
            kase, b[0].id);
        _for(i, 1, n) {
            bool vis = false;
            _for(j, 0, m - 1) if (visible(i, (x[j] + x[j + 1]) / 2)) {
                vis = true;
                break;
            }
            if(vis) printf(" %d", b[i].id);
        }
        printf("\n");
    }

    return 0;
}