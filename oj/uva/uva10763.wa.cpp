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
int n;

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    while (std::cin >> n && n != 0) {
        std::set<int> willEmpty, willOccupy;
        _for(idx, 0, n) {
            int A, B;
            std::cin >> A >> B;
            willEmpty.insert(A);
            willOccupy.insert(B);
        }
        if (willOccupy.size() == willOccupy.size()) {
            bool found = true;
            for (auto item : willOccupy) {
                if (!willEmpty.count(item)) {
                    found = false;
                    break;
                }
            }
            if (found) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
            continue;
        } else {
            std::cout << "NO" << std::endl;
            continue;
        }
    }
    return 0;
}