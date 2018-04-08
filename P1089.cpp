#include <iostream>

int main() {
    int money = 0, mum_save = 0, pay;
    for (int month = 1; month <= 12; month++) {
        std::cin >> pay;
        money += 300;
        money -= pay;
        if (money < 0) {
            std::cout << -month;
            return 0;
        }
        mum_save += (money / 100) * 100;
        money -= (money / 100) * 100;
    }

    std::cout << money + mum_save * 1.2;
    return 0;
}