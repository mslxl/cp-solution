#include <iostream>

int main() {
    int K;
    std::cin >> K;
    long double Sn = 0;
    for (int i = 1;; i++) {
        Sn += 1.0 / i;
        if (Sn > K) {
            std::cout << i;
            break;
        }
    }
    return 0;
}