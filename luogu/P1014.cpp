#include <iostream>

int main() {
    int N, r = 1, c = 1;
    std::cin >> N;
    int direct = 0;
    while (N > 1) {
        N--;
        switch (direct) {
            case 3:
                if (r != 1) {
                    r--;
                    c++;
                    break;
                }
            case 0:
                c++;
                direct = 1;
                break;
            case 1:
                if (c != 1) {
                    c--;
                    r++;
                    break;
                }
            case 2:
                r++;
                direct = 3;
                break;
        }
    }
    std::cout << r << '/' << c;
}