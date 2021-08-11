#include <iostream>

int main() {
    double m;
    double over_m = 0;
    double now_step = 2.0 / 0.98;
    std::cin >> m;
    int step = 0;
    while (m > over_m) {
        step++;
        now_step *= 0.98;
        over_m += now_step;
    }
    std::cout << step;
    return 0;
}