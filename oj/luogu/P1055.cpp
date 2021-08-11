#include <string>
#include <iostream>
#include <cstdio>

int main() {
    char c;
    int index = 0, sum = 0;
    std::string head;
    for (int i = 0; i < 12; ++i) {
        std::cin >> c;
        head += c;
        int num;
        if (c == '-')
            continue;
        else if (c == 'X')
            num = 10;
        else
            num = c - '0';
        index++;
        sum += num * index;
    }
    int result = sum % 11;
    std::cin >> c;
    int expect = c - '0' == 40 ? 10 : c - '0';
    if (result == expect) {
        std::cout << "Right";
    } else {
        std::cout << head;
        if (result == 10)
            std::cout << "X";
        else
            std::cout << result;
    }
    return 0;
}