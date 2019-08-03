#include<iostream>
#include<string>
#include <cmath>

using namespace std;
struct people {
    // 0 => outer
    // 1 => inner
    int face;
    std::string name;
};

int get_people_index(int & index, int length) {
    int i = index;
    if (i < 0) {
        i += (abs(i / length)+1) * length;
    }
    // 溢出了还行
    index = i;
    return i % length;
}

int main() {
    int m, n, a, s;
    std::cin >> n >> m;
    struct people ppl[n];
    for (int i = 0; i < n; i++) {
        std::cin >> ppl[i].face >> ppl[i].name;
    }
    int index = 0;
    for (int j = 0; j < m; j++) {
        std::cin >> a >> s;
        if (a == 0) {
            // Left
            if (ppl[get_people_index(index, n)].face == 0) {
                index -= s;
            } else {
                index += s;
            }
        } else {
            // Right
            if (ppl[get_people_index(index, n)].face == 0) {
                index += s;
            } else {
                index -= s;
            }
        }
    }
    std::cout << ppl[get_people_index(index, n)].name;
    return 0;
}


