#include <iostream>
#include <vector>
int N, M;

std::vector<int>* G;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> N >> M;
    G = new std::vector<int>(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
    }
}