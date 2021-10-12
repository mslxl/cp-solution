#include <string>
#include <iostream>
#include <cstdio>

void to_upper(std::string &string) {
    for (int i = 0; i < string.length(); ++i) {
        string[i] = static_cast<char>(toupper(string[i]));
    }
}

std::string get_word(const std::string &line, const unsigned int index) {
    for (int i = index; i < line.length(); ++i) {
        if (line[i] == ' ') {
            return line.substr(index, i - index);
        }
    }
    return line.substr(index);
}

int main() {
    //freopen("testdata/P1308/testdata.in","r",stdin);

    std::string target, line;
    int times = 0, first = -1;
    getline(std::cin, target);
    getline(std::cin, line);
    to_upper(target);
    to_upper(line);
    // 就是不用 find
    bool new_word = true;
    for (unsigned int i = 0; i < line.length(); ++i) {
        if (line[i] == ' ') {
            new_word = true;
            continue;
        }
        if (new_word) {
            std::string word = get_word(line, i);
            if (word == target) {
                if (first == -1) {
                    first = i;
                }
                times++;
            }
            new_word = false;
        }
    }
    if (first == -1) {
        std::cout << -1;
    } else {
        std::cout << times << " " << first;
    }
    return 0;
}
