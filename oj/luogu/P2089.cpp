#include <iostream>
#include <cstring>
#include <cstdio>

int N, num = 0;
char *str;

int main() {
    std::cin >> N;
    if (N > 10 * 3 || N < 10) {
        std::cout << 0;
        return 0;
    }
    str = new char[(N) * 21 * 20 * 20 * 50];
    char *tmp = new char[21];
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            for (int k = 1; k < 4; ++k) {
                for (int l = 1; l < 4; ++l) {
                    for (int m = 1; m < 4; ++m) {
                        for (int n = 1; n < 4; ++n) {
                            for (int o = 1; o < 4; ++o) {
                                for (int p = 1; p < 4; ++p) {
                                    for (int q = 1; q < 4; ++q) {
                                        for (int r = 1; r < 4; ++r) {
                                            if (i + j + k + l + m + n + o + p + q + r == N) {
                                                num++;
                                                sprintf(tmp, "%d %d %d %d %d %d %d %d %d %d\n", i, j, k, l, m, n, o, p,
                                                        q, r);
                                                strcat(str, tmp);
                                                memset(tmp, '\0', 21);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } // How beautiful is it!
    std::cout << num << std::endl << str;
    return 0;
}