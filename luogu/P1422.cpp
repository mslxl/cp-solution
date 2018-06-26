#include <iostream>
#include <iomanip>

int main() {

    const double lv1 = 0.4463;
    const double lv2 = 0.4663;
    const double lv3 = 0.5663;

    const double lv1_line = 150;
    const double lv2_line = 400;

    int total;
    double money = 0;

    std::cin >> total;

    if (total <= lv1_line) {
        money = total * lv1;
    } else if (total <= lv2_line) {
        money = lv1_line * lv1 + (total - lv1_line) * lv2;
    } else {
        money = lv1_line * lv1 + (lv2_line - lv1_line) * lv2 + (total - lv2_line) * lv3;
    }
    std::cout << std::fixed << std::setprecision(1) << money;
    return 0;
}