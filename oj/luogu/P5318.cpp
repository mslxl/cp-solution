#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
int n, m;
std::vector<int>* G;
int* status;

const int STATUS_UNREAD = 0;
const int STATUS_READING = 1;
const int STATUS_FIN = -1;

void dfs(int node) {
    if (status[node] != STATUS_UNREAD) {
        return;
    }
    std::cout << node << ' ';
    status[node] = STATUS_READING;
    if (!G[node].empty()) {
        std::sort(G[node].begin(), G[node].end());
        for (auto child : G[node]) {
            dfs(child);
        }
    }

    status[node] = STATUS_FIN;
}
void bfs(int root) {
    if (status[root] != STATUS_UNREAD) {
        return;
    }
    std::queue<int> queue;
    queue.push(root);
    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        std::cout << node << ' ';
        status[node] = STATUS_FIN;
        if (!G[node].empty()) {
            std::sort(G[node].begin(), G[node].end());
            for (auto next : G[node]) {
                if (status[next] == STATUS_UNREAD) {
                    status[next] = STATUS_READING;
                    queue.push(next);
                }
            }
        }
    }
}

void solve() {
    memset(status, 0, (n + 1) * sizeof(int));
    dfs(1);

    std::cout << std::endl;
    memset(status, 0, (n + 1) * sizeof(int));
    bfs(1);
}

int main(int argc, char const* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    G = new std::vector<int>[n + 1];
    status = new int[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        G[u].push_back(v);
    }
    solve();

    return 0;
}