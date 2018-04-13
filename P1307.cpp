#include <string>
#include <iostream>

int main() {
    std::string line;
    std::cin >> line;
    unsigned int first_num = 0;
    if (line[0] == '-')
        first_num = 1;
    for (unsigned int i = 0; i < (line.length() - first_num) / 2; ++i) {
        std::swap(line[first_num + i], line[line.length() - i - 1]);
    }
    while (line[first_num] == '0')
        line.erase(first_num, 1);
    std::cout << line;
}