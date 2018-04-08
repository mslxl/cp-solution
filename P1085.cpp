#include <iostream>

int main() {
    int unhappy_best_day = 0;
    int unhappy_best_value = 0;

    int school, outside;
    for (int day = 1; day <= 7; day++) {
        std::cin >> school >> outside;
        int study_time = outside + school;
        if (study_time > 8) {
            if (unhappy_best_value < study_time) {
                unhappy_best_day = day;
                unhappy_best_value = study_time;
            }
        }
    }
    std::cout << unhappy_best_day;
    return 0;
}