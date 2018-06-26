#include<iostream>

int main() {
    int day, start_day;
    std::cin >> start_day >> day;
    int over_m = 0;
    for (int i = start_day; i - start_day < day; i++) {
        int week_day = i % 7;
        if (week_day != 6 && week_day != 0) {
            over_m += 250;
        }
    }
    std::cout << over_m;
}