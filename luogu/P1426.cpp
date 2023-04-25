#include <iostream>

int main() {
    int s, x;
    double location = 0, speed = 7;
    bool warn = false;

    std::cin >> s >> x;

    while (true) {
        if (s + x >= location && s - x <= location) {
            if (warn) {
                std::cout << 'y';
                return 0;
            }
            warn = true;

        } else if (s + x < location && warn) {
            break;
        }
        location += speed;
        speed *= 0.98;
    }
    std::cout << 'n';
    return 0;
}