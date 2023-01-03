#include <iostream>

int main() {
    int apples[10];
    for (int i = 0; i < 10; i++) {
        std::cin >> apples[i];
    }
    int hand;
    int apple = 0;
    std::cin >> hand;
    hand += 30;
    for (int i = 0; i < (sizeof(apples) / sizeof(int)); i++) {
        if (apples[i] <= hand) {
            apple++;
        }
    }
    std::cout << apple;
}