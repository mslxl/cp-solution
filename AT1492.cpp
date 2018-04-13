#include <string>
#include <iostream>
#include <map>

std::string s;

int main() {
    std::cin >> s;

    if (s.length() % 6 != 0) {
        std::cout << "No" << std::endl;
        return 0;
    }
    unsigned long titech_num = s.length() / 6;

    std::map<char, int> m;
    int i = 0;
    for (; i < titech_num * 6; i++) {
        m[s[i]]++;
        if (m['t'] < m['i'] ||
            m['t'] < m['e'] * 2 ||
            m['i'] < m['e'] ||
            m['e'] < m['c'] ||
            m['c'] < m['h'] ||
            (m['t'] > titech_num &&
             m['i'] < m['t'] - titech_num))
            break;
    }

    if (i < titech_num * 6 ||
        m['t'] != titech_num * 2 ||
        m['i'] != titech_num ||
        m['e'] != titech_num ||
        m['c'] != titech_num ||
        m['h'] != titech_num) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }
    return 0;
}
