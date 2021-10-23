#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
#define _br() std::cout << std::endl
typedef long long ll;
typedef unsigned long long ull;
int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    std::string line;
    while (getline(std::cin, line)) {
        std::deque<std::string> queue;
        std::string tmp;
        bool is_last_home = false;
        for (auto ch : line) {
            if (ch == '[') {
                queue.push_back(tmp);
                is_last_home = true;
                tmp.clear();
            } else if (ch == ']') {
                queue.push_front(tmp);
                is_last_home = false;
                tmp.clear();
            } else {
                tmp.push_back(ch);
            }
        }
        if (!tmp.empty()) {
            if (is_last_home) {
                queue.push_front(tmp);
            } else {
                queue.push_back(tmp);
            }
        }
        for (auto str : queue) {
            std::cout << str;
        }
        _br();
    }

    return 0;
}