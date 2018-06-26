#include <iostream>

int main() {
    int n, x, times = 0;
    std::cin >> n >> x;
    for (int index = 1; index <= n; index++) {
        int number = index;
        do {
            int first_bit = number % 10;
            if (first_bit == x) {
                times++;
            }
            number /= 10;
        } while (number != 0);
    }
    std::cout << times;
}