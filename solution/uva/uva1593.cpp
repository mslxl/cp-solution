#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#define _for(i, init, lim) for (int i = (init); i < (lim); i++)
#define _rep(i, init, lim_eq) for (int i = (init); i <= (lim_eq); ++i)
#define _br() std::cout << std::endl;
typedef long long ll;
typedef unsigned long long ull;
std::vector<std::vector<std::string>> input;
std::map<int, int> cols_len;
void print_ex(std::string wd, int width) {
    std::cout << wd;
    if (wd.size() <= width) {
        _rep(i, 1, width - wd.size()) { std::cout << ' '; }
    }
}
int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    std::string line;
    while (getline(std::cin, line)) {
        std::stringstream ss;
        ss << line;

        std::string wd;
        std::vector<std::string> wds;
        for (int idx = 0; ss >> wd; idx++) {
            if (cols_len.count(idx)) {
                cols_len[idx] = std::max((int)wd.size(), cols_len[idx]);
            } else {
                cols_len[idx] = (int)wd.size();
            }
            wds.push_back(wd);
        }
        input.push_back(wds);
    }
    for (auto line : input) {
        _for(c, 0, line.size()) {
            if (c == line.size() - 1) {
                std::cout << line[c];
            } else {
                print_ex(line[c], cols_len[c] + 1);
            }
        }
        std::cout << std::endl;
    }

    return 0;
}