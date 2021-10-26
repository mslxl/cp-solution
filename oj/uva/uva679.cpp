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
typedef long long ll;
typedef unsigned long long ull;

int D;  // Max depth
int I;  // I-th ball
int drop(int idx_ball, int this_node, int depth) {
    if (depth == D) {
        return this_node;
    }
    if (idx_ball % 2 == 0) {
        return drop((idx_ball) / 2, 2 * this_node + 1, depth + 1);
    } else {
        return drop((idx_ball + 1) / 2, 2 * this_node, depth + 1);
    }
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int l;  // num of test case
    std::cin >> l;

    while (l--) {
        std::cin >> D;
        if (D == -1) {
            break;
        }
        std::cin >> I;
        std::cout << drop(I, 1, 1) << std::endl;
    }
    return 0;
}