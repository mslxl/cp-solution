#include <iostream>

int main() {
    int offset;
    std::string pwd;
    std::cin >> offset;
    std::cin >> pwd;
    if (offset >= 26)
        offset %= 26;
    for (int i = 0; i < pwd.length(); ++i) {
        int code = (int) pwd[i] + offset;
        while (code > 122)
            code -= 26;
        pwd[i] = (char) code;
    }
    std::cout << pwd;

    return 0;
}