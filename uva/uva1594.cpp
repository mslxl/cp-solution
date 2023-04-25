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
int T;

bool isAllZero(const std::vector<int>& arr) {
    for (auto i : arr) {
        if (i != 0) {
            return false;
        }
    }
    return true;
}

bool tryDucci(std::vector<int>& arr, int times) {
    if (isAllZero(arr))
        return true;
    else if (times == 1000)
        return false;
    int first = arr[0];
    _for(idx, 0, arr.size()) {
        if (idx != arr.size() - 1) {
            arr[idx] = abs(arr[idx] - arr[idx + 1]);
        } else {
            arr[idx] = abs(arr[idx] - first);
        }
    }
    return tryDucci(arr, ++times);
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    _for(case_id, 0, T) {
        int num;
        std::cin >> num;
        std::vector<int> arr;
        _for(idx, 0, num) {
            int v;
            std::cin >> v;
            arr.push_back(v);
        }
        if (tryDucci(arr, 1)) {
            std::cout << "ZERO" << std::endl;
        } else {
            std::cout << "LOOP" << std::endl;
        }
    }

    return 0;
}