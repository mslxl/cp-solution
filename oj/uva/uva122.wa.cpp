#include <algorithm>
#include <cctype>
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
typedef std::pair<int, std::string> node;

struct Functor {
    bool operator()(node n1, node n2) {
        if (n1.second.size() != n2.second.size()) {
            return n1.second.size() < n2.second.size();
        } else {
            int len = n1.second.size();
            _for(idx, 0, len) {
                auto c1 = n1.second[idx], c2 = n2.second[idx];
                if (c1 - c2 != 0) {
                    return c1 - c2 < 0;
                }
            }
            return false;
        }
    }
};

std::set<node, Functor> nodes;

int str2int(std::string wd) {
    int num = 0;
    for (auto ch : wd) {
        num *= 10;
        num += (ch - '0');
    }
    return num;
}

node ext_node(std::string wd) {
    int pos_comma = wd.find(",");
    auto node =
        std::make_pair(str2int(wd.substr(1, pos_comma - 1)),
                       wd.substr(pos_comma + 1, wd.size() - pos_comma - 2));
    return node;
}

void end_tree() {
    for (auto it : nodes) {
        std::cout << it.first << ' ';
    }
    _br();
    nodes.clear();
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    std::string wd;
    while (std::cin >> wd) {
        if (wd.size() == 2) {
            end_tree();
            continue;
        } else {
            nodes.insert(ext_node(wd));
        }
    }

    return 0;
}