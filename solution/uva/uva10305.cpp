#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
int n, m;
std::vector<int>* G = nullptr;
std::queue<int> queue;
int* c = nullptr;

bool dfs(int node) {
    if (c[node] == -1) {  // -1 标志着访问中
        return false;     // 有环
    }
    c[node] = -1;

    for (int child : G[node]) {
        if (c[child] == -1) {
            return false;
        } else if (c[child] == 0 && !dfs(child)) {
            return false;
        }
    }

    c[node] = 1;
    queue.push(node);
    return true;
}

void solve() {
    queue = std::queue<int>();
    for (int i = 1; i <= n; i++)
        if (c[i] == 0)
            dfs(i);
    while (!queue.empty()) {
        std::cout << queue.front() << ' ';
        queue.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    while (std::cin >> n >> m && !(n == 0 && m == 0)) {
        G = new std::vector<int>[n + 1];
        c = new int[n + 1];
        memset(c,0,(n + 1) * sizeof(int));
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            G[v].push_back(u);
        }
        solve();
        delete[] G;
        delete[] c;
    }
    return 0;
}