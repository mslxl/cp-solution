#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>


int main() {
    int num, max = 0, totl = 0;
    std::string who;
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        std::string name;
        int endMark, giveMark, artNum;
        char temp;
        bool isGanBu, isWestern;

        std::cin >> name >> endMark >> giveMark >> temp;
        isGanBu = temp == 'Y';
        std::cin >> temp;
        isWestern = temp == 'Y';
        std::cin >> artNum;

        int RMB = 0;
        if (endMark > 80 && artNum > 0) RMB += 8000;
        if (endMark > 85 && giveMark > 80) RMB += 4000;
        if (endMark > 90) RMB += 2000;
        if (endMark > 85 && isWestern) RMB += 1000;
        if (giveMark > 80 && isGanBu) RMB += 850;

        if (RMB > max) {
            max = RMB;
            who = name;
        }
        totl += RMB;
    }
    std::cout << who << std::endl << max << std::endl << totl;
    return 0;
}