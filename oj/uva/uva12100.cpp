#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
#define _br() std::cout << std::endl;
typedef long long ll;
typedef unsigned long long ull;
int T;

struct Work {
    int pri;
    bool target;
};

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    _for(T_idx, 0, T) {
        int num_work, target_pos;
        int used_time = 0;
        std::cin >> num_work >> target_pos;
        std::queue<Work> queue_work;
        std::priority_queue<int, std::vector<int>, std::less<int> > pris;
        _for(idx, 0, num_work) {
            Work w;
            std::cin >> w.pri;
            pris.push(w.pri);
            w.target = idx == target_pos;
            queue_work.push(w);
        }
        while (true) {
            int top_pri = pris.top();
            pris.pop();
            while (queue_work.front().pri != top_pri) {
                queue_work.push(queue_work.front());
                queue_work.pop();
            }
            used_time++;
            if (queue_work.front().target) {
                break;
            } else {
                queue_work.pop();
            }
        }
        std::cout << used_time << std::endl;
    }
    return 0;
}