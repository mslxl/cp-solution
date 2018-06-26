#include <iostream>

struct apple {
    int height;
    int cost;
};

int n, s, a, b, picked = 0;
apple *apples;

int pick() {
    for (int i = 0; i < n; ++i) {
        if (a + b >= (apples + i)->height && s >= (apples + i)->cost) {
            s -= (apples + i)->cost;
            picked++;
        }
    }
    return picked;
}

void sort() {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((apples + i)->cost > (apples + j)->cost) {
                std::swap((apples + i)->cost, (apples + j)->cost);
                std::swap((apples + i)->height, (apples + j)->height);
            }
        }
    }
}

int main() {
    std::cin >> n >> s >> a >> b;
    apples = new apple[n];
    for (int i = 0; i < n; ++i) {
        int xi, yi;
        std::cin >> xi >> yi;
        (apples + i)->height = xi;
        (apples + i)->cost = yi;
    }
    sort();
    std::cout << pick();
    return 0;
}