#include <iostream>

int main() {
    int day_num;
    std::cin >> day_num;
    int temp, max_days = 0, days = 1, lastTemp = 0;
    std::cin >> lastTemp;
    for (int i = 1; i < day_num; ++i) {
        std::cin >> temp;
        if (temp > lastTemp) {
            days++;
        } else {
            days = 1;
        }
        if (days > max_days) {
            max_days = days;
        }
        lastTemp = temp;
    }
    std::cout << max_days;
}