#include <iostream>
int main(int argc, char *argv[]) {
    int min=1000,count, v;
    std::cin >> count;
    for (int i = 0; i < count; i++) {
        std::cin >> v;
        min = std::min(v, min);
    }
    std::cout << min;
    return 0;
}
