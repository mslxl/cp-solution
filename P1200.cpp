#include <iostream>

int mod(std::string name) {
    int result = 1;
    for (int i = 0; i < name.length(); ++i) {
        result *= (name[i] - 64);
    }
    return result % 47;
}

int main() {
    std::string meteor, team;
    std::cin >> meteor >> team;
    if (mod(meteor) == mod(team)) {
        std::cout << "GO";
    } else {
        std::cout << "STAY";
    }
    return 0;
}