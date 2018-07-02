
#include <iostream>

int n, m, v, s, x;

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        std::cin >> v;
        if (v == 1) {
            ++s;
        }
        if (i % m == 0) {
            x = x > s ? x : s, s = 0;
        }
    }
    std::cout << x << std::endl;
    return 0;
}