#include <string>
#include <map>
#include <iostream>


int main() {
    // 扫描字符
    std::map<char, int> m;
    std::string line;
    for (int i = 0; i < 4; ++i) {
        std::getline(std::cin, line);
        for (int j = 0; j < line.length(); ++j) {
            m[line[j]]++;
        }
    }

    // 排出最大高度
    int max_height = 0;
    for (int k = 'A'; k <= 'Z'; ++k) {
        if (m[k] > max_height) {
            max_height = m[k];
        }
    }

    // 打 *
    for (int now_height = max_height; now_height > 0; --now_height) {
        for (int k = 'A'; k <= 'Z'; ++k) {
            if (m[k] >= now_height)
                std::cout << "*";
            else
                std::cout << " ";

            if (k != 'Z')
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    for (char k = 'A'; k <= 'Z'; ++k) {
        std::cout.put(k);
        if (k != 'Z')
            std::cout.put(' ');
    }
    return 0;
}