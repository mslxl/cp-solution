#include <iostream>
#include <cstring>

#define USE(x) if (used[(x)]) { continue; } else { used[(x)] = true; }
#define FREE(x) used[(x)] = false;

int A, B, C;
bool used[10];
bool haveAnswer = false;

// 暴力出奇迹
int main() {
    std::cin >> A >> B >> C;

    for (int i = 1; i < 10; ++i) {
        memset(used, false, sizeof(used));
        USE(i)
        for (int j = 1; j < 10; ++j) {
            USE(j)
            for (int k = 1; k < 10; ++k) {
                USE(k)
                //------------------
                for (int l = 1; l < 10; ++l) {
                    USE(l)
                    for (int m = 1; m < 10; ++m) {
                        USE(m)
                        for (int n = 1; n < 10; ++n) {
                            USE(n)
                            //---------------------
                            for (int o = 1; o < 10; ++o) {
                                USE(o)
                                for (int p = 1; p < 10; ++p) {
                                    USE(p)
                                    for (int q = 1; q < 10; ++q) {
                                        USE(q)
                                        double a = i * 100 + j * 10 + k, b = l * 100 + m * 10 + n, c =
                                                o * 100 + p * 10 + q;

                                        if (a / A == b / B && b / B == c / C && c / C == a / A) {
                                            std::cout << a << " " << b << " " << c << std::endl;
                                            haveAnswer = true;
                                        }

                                        FREE(q)
                                    }
                                    FREE(p)
                                }
                                FREE(o)
                            }
                            FREE(n)
                        }
                        FREE(m)
                    }
                    FREE(l)
                }
                FREE(k)
            }
            FREE(j)
        }
        FREE(i)
    }
    if (!haveAnswer)
        std::cout << "No!!!";
}