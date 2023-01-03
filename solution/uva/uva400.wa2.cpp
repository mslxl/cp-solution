#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using std::string;
typedef long long ll;
typedef unsigned long long ull;
int num_line;
std::string* names = nullptr;

const int max_cols_size = 60;
int max_name_size = 0;
int num_cols, num_rows, num_last_col_remain;
void hr() {
    for (int i = 0; i < max_cols_size; i++) {
        std::cout << '-';
    }
    std::cout << std::endl;
}

int locate_pos(int r, int c) {
    int pos = 0;

    pos += (c - 1) * num_rows;
    pos += r;

    if (pos > num_line)
        return -1;
    else
        return pos - 1;
}

void print_ex(const std::string& str, int c) {
    std::cout << str;
    int sp = (c != num_cols ? max_name_size + 2 : max_name_size) - str.size();
    for (int i = 0; i < sp; i++) {
        std::cout << ' ';
    }
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    while (std::cin >> num_line) {
        max_name_size = 0;
        names = new std::string[num_line];
        for (int i = 0; i < num_line; i++) {
            std::cin >> names[i];
            if (names[i].size() > max_name_size) {
                max_name_size = names[i].size();
            }
        }
        std::sort(names, names + num_line);
        num_cols = (max_cols_size - max_name_size) / (max_name_size + 2) + 1;

        if (num_cols == 1) {
            num_last_col_remain = 0;
        } else if (num_cols == 2) {
            num_last_col_remain = num_line / 2;
        } else {
            num_last_col_remain = num_line % (num_cols - 1);
        }
        if (num_cols == 1) {
            num_rows = num_line;
        } else {
            num_rows = (num_line - num_last_col_remain) / (num_cols - 1);
        }

        hr();
        for (int r = 0; r < num_rows; r++) {
            for (int c = 0; c < num_cols; c++) {
                int pos = locate_pos(r + 1, c + 1);
                if (pos == -1) {
                    continue;
                }
                print_ex(names[pos], c + 1);
            }
            std::cout << std::endl;
        }
        delete[] names;
    }

    return 0;
}