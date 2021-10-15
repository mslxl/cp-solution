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
struct Building {
    int id = 0;
    int x, y, w, d, h;
    bool operator<(const Building& rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
};

std::istream& operator>>(std::istream& is, Building& obj) {
    is >> obj.x >> obj.y >> obj.w >> obj.d >> obj.h;
}
int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int num_building;
    while (std::cin >> num_building && num_building != 0) {
        std::vector<Building> bs;
        _for(idx, 0, num_building) {
            Building b;
            b.id = idx;
            std::cin >> b;
            bs.push_back(b);
        }
        std::sort(bs.begin(), bs.end());
        bs.erase(std::unique(bs.begin(), bs.end()));
        for (auto xRange : bs) {
            int fromX = xRange.x, endX = xRange.x + xRange.w;
            _rep(x, fromX, endX){
                

            }
        }
    }

    return 0;
}