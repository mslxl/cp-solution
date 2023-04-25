#include <cstdio>
#include <vector>
const int maxm = 1e5 + 10;
int N, M;

std::vector<int> G[maxm];
int vis[maxm] = {0};

void dfs(int node, int times) {
    if (vis[node] == 0) {
        vis[node] = times;
        for (auto item : G[node]) {
            dfs(item, times);
        }
    }
}

int main(int argc, char const* argv[]) {
    scanf("%d%d", &N, &M);
    int u, v;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &u, &v);
        // G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = N; i > 0; i--) {
        dfs(i, i);
    }
    for(int i = 1; i <= N; i++){
        printf("%d ", vis[i]);
    }

    return 0;
}
