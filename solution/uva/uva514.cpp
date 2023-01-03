#include <iostream>
#include <queue>
#include <stack>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
start:
    int T;
    std::cin >> T;
    while (T) {
        int* target = new int[T];
        int statified_idx = 0;
        std::queue<int> trains;
        std::stack<int> station;
        _for(idx, 0, T) {
            std::cin >> target[idx];
            if (target[idx] == 0) {
                std::cout << std::endl;
                goto start;
            }
            trains.push(idx + 1);
        }
        while (!trains.empty() || !station.empty()) {
            if (station.empty() || target[statified_idx] != station.top()) {
                if (trains.empty()) {
                    break;
                } else {
                    station.push(trains.front());
                    trains.pop();
                }
            } else {
                statified_idx++;
                station.pop();
            }
        }
        std::cout << (statified_idx == T ? "Yes" : "No") << std::endl;
    }

    return 0;
}