#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define _for(vName, init, lim) for (int vName = (init); vName < (lim); vName++)
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long ll;
typedef unsigned long long ull;

const int max_cols = 60;
int n;
int num_max_name_len = 0;
std::string* names = nullptr;
void hr() {
    _rep(i, 1, max_cols) std::cout << '-';
    std::cout << std::endl;
}

void print_ex(const std::string& str, int width) {
    std::cout << str;
    if (str.size() < width) {
        _rep(i, 1, width - str.size()) { std::cout << ' '; }
    }
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    while (std::cin >> n) {
        names = new std::string[n];
        _for(i, 0, n) {
            std::cin >> names[i];
            num_max_name_len = std::max((int)names[i].size(), num_max_name_len);
        }
        std::sort(names, names + n);
        int cols = (max_cols - num_max_name_len) / (num_max_name_len + 2) + 1;
        int rows = (n - 1) / cols + 1;
        hr();
        _for(r, 0, rows) {
            _for(c, 0, cols) {
                int idx = c * rows + r;
                int width =
                    c == cols - 1 ? num_max_name_len : num_max_name_len + 2;
                if (idx < n)
                    print_ex(names[idx], width);
            }
            std::cout << std::endl;
        }
        num_max_name_len = 0;
        delete[] names;
    }

    return 0;
}