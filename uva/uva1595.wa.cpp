#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
#define _br() std::cout << std::endl;
typedef long long ll;
typedef unsigned long long ull;
int T;
struct Point {
    int x, y;
    bool operator<(const Point& ghs) const {
        return x < ghs.x || (x == ghs.x && y < ghs.y);
    }
};

std::vector<Point> pts;
std::map<int, std::vector<Point>> ptsInX;
std::set<int> searchedX;

bool searchX(int x, int flipX) {
    auto& leftPs = ptsInX[x];
    auto& rightPs = ptsInX[flipX];
    if (leftPs.size() != rightPs.size())
        return false;
    std::sort(leftPs.begin(), leftPs.end());
    std::sort(rightPs.begin(), rightPs.end());
    _for(idx, 0, leftPs.size()) {
        if (leftPs[idx].y != rightPs[idx].y) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin >> T;

    _for(case_idx, 0, T) {
        int num_group;
        std::cin >> num_group;
        _for(idx, 0, num_group) {
            Point p;
            std::cin >> p.x >> p.y;
            pts.push_back(p);
            if (!ptsInX.count(p.x)) {
                ptsInX[p.x] = std::vector<Point>();
            }
            ptsInX[p.x].push_back(p);
        }
        std::sort(pts.begin(), pts.end());
        int left = 0, right = pts.size() - 1;
        bool mirror = true;
        const int axis = (pts[left].x + pts[right].x) / 2;
        while (right > left) {
            if (searchedX.count(left)) {
                continue;
            }
            searchedX.insert(right);
            searchedX.insert(left);
            if (!searchX(right, left)) {
                mirror = false;
                break;
            }else if( (pts[left].x + pts[right].x) / 2 != axis){
                mirror = false;
                break;
            }
            right--;
            left++;
        }
        if (mirror)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;

        pts.clear();
        searchedX.clear();
        ptsInX.clear();
    }

    return 0;
}