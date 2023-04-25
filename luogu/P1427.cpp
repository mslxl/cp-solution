#include <iostream>

int main() {
    int number[100], in = 0, index = 0;
    do {
        std::cin >> in;
        number[index] = in;
        index++;
    } while (in != 0);
    for (int i = index - 2; i >= 0; i--) {
        std::cout << number[i];
        if (i > 0) {
            std::cout << ' ';
        }
    }
}