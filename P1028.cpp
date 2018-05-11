#include<iostream>

// TODO TLE
int each(int num, int src) {
    int times = 0;
    for (int i = 1; i <= num / 2; i++) {
        times++;
        times += each(i, src);
    }
    return times;
}

int main() {
    int num;
    std::cin >> num;
    std::cout << each(num, num) + 1;
    return 0;
}
