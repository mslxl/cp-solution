#include <cmath>
#include <iostream>
#include <queue>

int main() {
    std::queue<std::pair<int, int>> que;
    int n;
    std::cin >> n;
    n = pow(2, n);
    for (int i = 1; i <= n; i++) {
        int ab;
        std::cin >> ab;
        que.push(std::make_pair(i, ab));
    }
    while (que.size() > 2) {
        std::pair<int, int> f1 = que.front();
        que.pop();
        std::pair<int, int> f2 = que.front();
        que.pop();
        if (f1.second > f2.second) {
            que.push(f1);
        } else {
            que.push(f2);
        }
    }
    std::pair<int, int> f1 = que.front();
    que.pop();
    std::pair<int, int> f2 = que.front();
    if (f1.second < f2.second) {
        std::cout << f1.first;
    } else {
        std::cout << f2.first;
    }
}