#include<iostream>
#include <stdio.h>

int main() {
    int m, s, m1, s1;
    std::cin >> m >> s >> m1 >> s1;
    s += m * 60;
    s1 += m1 * 60;

    printf("%d %d", (s1 - s) / 60, (s1 - s) % 60);
    std::cin >> m;
    return 0;
}