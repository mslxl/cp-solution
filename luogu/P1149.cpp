#include<iostream>
#include <cstring>

int matches, num = 0;

int mapping[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int getmatches(int num) {
    if (num < 10) {
        return mapping[num];
    } else {
        int match = getmatches(num % 10);
        while (num > 9) {
            num /= 10;
            match += getmatches(num % 10);
        }
        return match;
    }
}

int main() {
    std::cin >> matches;
    matches -= 4;
    // 暴力出奇迹
    for (int i = 0; i < 1111; ++i) {
        for (int j = 0; j < 1111; ++j) {
            int sum = i + j;
            int cost = getmatches(sum) + getmatches(i) + getmatches(j);
            if (cost == matches) {
                num++;
            }
        }
    }
    std::cout << num;
    return 0;
}