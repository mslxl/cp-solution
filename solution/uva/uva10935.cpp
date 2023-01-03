#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
#define _br() std::cout << std::endl;
typedef long long ll;
typedef unsigned long long ull;
int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int num;
    while (std::cin >> num && num != 0) {
        std::queue<int> que;
        _rep(idx, 1, num) { que.push(idx); }
        std::cout << "Discarded cards:";
        if (que.size() == 1)
            goto end;
        std::cout << ' ' << que.front();
        que.pop();
        que.push(que.front());
        que.pop();
        while (que.size() > 1) {
            std::cout << ", " << que.front();
            que.pop();
            que.push(que.front());
            que.pop();
        }
    end:
        std::cout << std::endl << "Remaining card: " << que.back() << std::endl;
    }

    return 0;
}