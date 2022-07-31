#include<bits/stdc++.h>
int n,m;
const int maxn = 4e4 + 17;

struct {
    int next;
    int to;
    int len;
} edges[maxn * 2 + 1];
int heads[maxn] = {0}, eid = 0;

void add_edge(int u,int v, int w){
    eid++;
    edges[eid].to = v;
    edges[eid].len = w;
    edges[eid].next = heads[u];
    heads[u] = eid;
}
int parent[maxn];
int depth[maxn];
unsigned long long dist[maxn];
bool vis[maxn];
int F[maxn][21];

void dfs(int u, int d=1){
    depth[u] = d;
    vis[u] = true;
    for(int i = heads[u]; i != 0; i = edges[i].next){
        const int v= edges[i].to;
        if(!vis[v]){
            parent[v] = u;
            dist[v]  = dist[u] + edges[i].len;
            dfs(v, d+1);
        }
    }
}

void ST_create(){
    for(int i = 1; i <= n;i++){
        F[i][0] = parent[i];
    }
    const int k = std::log2(n);

    for(int j = 1; j <= k; j++){
        for(int i = 1; i <= n;i++){
            F[i][j] = F[F[i][j-1]][j-1];
        }
    }
}

int LCA(int x, int y){
    if(depth[x] > depth[y]){
        std::swap(x,y);
    }
    const int k = std::log2(n);
    int result = 0;
    for(int i = k; i>=0;i--){
        if(depth[F[y][i]] >= depth[x]){
            y = F[y][i];
        }
    }
    if(x == y) return x;

    for(int i = k; i >= 0; i--){
        if(F[x][i] != F[y][i]){
            x = F[x][i];
            y = F[y][i];
        }
    }
    return F[x][0];
}

void solve(){
    std::memset(edges,0,sizeof(edges));
    std::memset(heads, 0, sizeof(heads));
    std::memset(parent, 0,sizeof(parent));
    std::memset(depth, 0,sizeof(depth));
    std::memset(vis, false, sizeof(vis));
    std::memset(F, 0,sizeof(F));
    std::memset(dist, 0,sizeof(dist));
    eid=0;
    std::cin >> n >> m;
    for(int i = 0; i < n-1;i++){
        int u,v,w;
        std::cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dfs(1);
    ST_create();
    for(int i = 0; i < m; i++){
        int x,y;
        std::cin >>x >> y;
        int nca = LCA(x, y);
        std::cout << (dist[x] + dist[y] - 2 * dist[nca]) << std::endl;
    }

}

int main(){
    int T;
    std::cin >> T;
    while(T--){
        solve();
    }
}