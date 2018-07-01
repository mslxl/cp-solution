#include <iostream>
#include <cstring>

int main() {
    int size, result = 0;
    std::cin >> size;
    int *num = new int[size];
    bool *tag = new bool[size];
    memset(tag, false, size);
    for (int i = 0; i < size; ++i)
        std::cin >> num[i];
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            if (i == j)
                continue;
            for (int k = 0; k < size; ++k) {
                if (k == j || k == i)
                    continue;
                if (num[i] + num[k] == num[j] && !tag[j]) {
                    tag[j] = true;
                    result++;
                }
            }
        }
    }
    std::cout << result;
    return 0;
}