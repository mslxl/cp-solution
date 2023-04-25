#include <cstdio>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>
int main(int argc, char *argv[]) {
    int abc[3];
    scanf("%d%d%d", &abc[0], &abc[1], &abc[2]);
    std::sort(std::begin(abc), std::end(abc));
    std::string str;
    std::cin >> str;
    for (int i = 0; i < 3; i++) {
        printf("%d", abc[str[i] - 'A']);
        if(i != 2) printf(" ");
    }
    return 0;
}
