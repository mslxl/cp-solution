#include <iostream>
#include <cstring>

int main() {
    int size, num;
    std::cin >> size >> num;
    int *road = new int[size];
    memset(road, 0, size);
    for (int j = 0; j < num; j++) {
        int start, end;
        std::cin >> start >> end;
        for (int i = start; i <= end; i++) {
            *(road + i) = 1;
        }
    }
    int tree_alive = 0;
    for (int k = 0; k <= size; k++) {
        if (*(road + k) == 0)
            tree_alive++;
    }
    std::cout << tree_alive;
    return 0;
}