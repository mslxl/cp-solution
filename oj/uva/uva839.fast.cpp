#include <iostream>
// 看了一遍书写的，根本不构建树真是 tql
bool solve(int& W) {
    int wl, dl, wr, dr;
    std::cin >> wl >> dl >> wr >> dr;
    int bl = true, br = true;
    if (wl == 0)
        bl = solve(wl);
    if (wr == 0)
        br = solve(wr);
    W = wl + wr;
    return bl && br && (wl * dl == wr * dr);
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    int W;
    while (T--) {
        bool ban = solve(W);
        std::cout << (ban ? "YES" : "NO") << std::endl;
        if (T != 0)
            std::cout << std::endl;
    }

    return 0;
}