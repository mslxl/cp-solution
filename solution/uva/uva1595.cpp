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
bool equal(std::vector<int> v1, std::vector<int> v2) {
    if (v1.size() != v2.size())
        return false;
    _for(idx, 0, v1.size()) {
        if (v1[idx] != v2[idx])
            return false;
    }
    return true;
}
int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int T, N;
    std::cin >> T;
    _for(idx_t, 0, T) {
        std::map<int, std::vector<int>> pts;
        std::vector<int> xs;
        std::cin >> N;
        _for(idx_n, 0, N) {
            int x, y;
            std::cin >> x >> y;
            if (!pts.count(x)) {
                pts[x] = std::vector<int>();
            }
            pts[x].push_back(y);
            xs.push_back(x);
        }
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

        int left = 0, right = xs.size() - 1;
        double filp_axis = (xs[right] + xs[left]) * 1.0 / 2;
        bool found = true;
        while (left < right) {
            auto &left_ys = pts[xs[left]], &right_ys = pts[xs[right]];
            std::sort(left_ys.begin(), left_ys.end());
            std::sort(right_ys.begin(), right_ys.end());

            if ((xs[left] + xs[right]) * 1.0 / 2 != filp_axis ||
                !equal(left_ys, right_ys)) {
                std::cout << "NO" << std::endl;
                found = false;
                break;
            }
            left++;
            right--;
        }
        if (found) {
            std::cout << "YES" << std::endl;
        }
    }

    return 0;
}