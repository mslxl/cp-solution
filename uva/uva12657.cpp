#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
typedef unsigned long long ull;
int *right = nullptr, *left = nullptr;

void link(int L, int R) {
    right[L] = R;
    left[R] = L;
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int n, m;
    int cmd, X, Y;
    int kase = 0;
    while (std::cin >> n >> m) {
        bool invert = false;
        right = new int[n + 1];
        left = new int[n + 1];
        for (int idx = 1; idx <= n; idx++) {
            left[idx] = idx - 1;
            right[idx] = (idx + 1) % (n + 1);
        }
        right[0] = 1, left[0] = n;
        while (m--) {
            std::cin >> cmd;
            if (cmd != 4) {
                std::cin >> X >> Y;
                const int LX = left[X], LY = left[Y], RX = right[X],
                          RY = right[Y];
                if (invert && cmd < 3) {
                    cmd = 3 - cmd;
                }
                if (cmd == 1) {
                    // Move X to the left of Y
                    if (LY == X) {
                        continue;
                    }
                    link(LX, RX);
                    link(LY, X);
                    link(X, Y);
                } else if (cmd == 2) {
                    // Move X to the right of Y
                    if (RY == X) {
                        continue;
                    }
                    link(LX, RX);
                    link(X, RY);
                    link(Y, X);
                } else if (cmd == 3) {
                    // Swap X and Y
                    if (LX == Y) {
                        link(X, Y);
                        link(LY, X);
                        link(Y, RX);

                    } else if (RX == Y) {
                        link(Y, X);
                        link(LX, Y);
                        link(X, RY);

                    } else {
                        link(LX, Y);
                        link(Y, RX);
                        link(LY, X);
                        link(X, RY);
                    }
                }
            } else {
                invert = !invert;
            }
        }
        bool odd = true;
        ull sum = 0;
        int cur;
        if (invert && n % 2 == 0) {
            cur = right[0];
            for (int idx = 1; idx <= n; idx++) {
                if (idx % 2 == 0) {
                    sum += cur;
                }
                cur = right[cur];
            }
        } else {
            cur = right[0];
            for (int idx = 1; idx <= n; idx++) {
                if (idx % 2 == 1) {
                    sum += cur;
                }
                cur = right[cur];
            }
        }
        std::cout << "Case " << (++kase) << ": " << sum << std::endl;

        delete[] right;
        delete[] left;
    }

    return 0;
}