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
bool* node;
inline int left(int k) {
    return 2 * k;
}
inline int right(int k) {
    return 2 * k + 1;
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int l;  // num of test case
    std::cin >> l;
    int D;  // Max depth
    int I;  // I-th ball

    while (l--) {
        std::cin >> D;
        if(D == -1){
            break;
        }
        std::cin >> I;
        int n = (int)pow(2, D) + 10;
        node = new bool[n];
        memset(node, false, sizeof(bool) * n);
        _rep(idx, 1, I) {
            int cur_depth = 1;
            int cur_node = 1;
            while (cur_depth != D) {
                bool switch_stat = node[cur_node];
                node[cur_node] = !switch_stat;
                cur_node = switch_stat ? right(cur_node) : left(cur_node);
                cur_depth++;
            }
            if (idx == I) {
                // This is target ball
                std::cout << cur_node << std::endl;
            }
        }
        delete[] node;
    }
    return 0;
}