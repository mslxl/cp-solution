#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

int main() {
    int need, num, value, money = INT_MAX;
    std::cin >> need;
    for (int i = 0; i < 3; ++i) {
        std::cin >> num >> value;
        int t = static_cast<int>(std::ceil(need * 1.0 / num) * value);
        money = std::min(t, money);
    }
    std::cout << money;
    return 0;
}
