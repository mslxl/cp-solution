#include<iostream>
#include<cstring>
#include<sstream>
#include<vector>
#include<stack>
#include<cmath>
const int maxn = 100;
int N;

struct Edge{
    int to;
    int next;
}edges[maxn * maxn + 17];
int heads[maxn + 17], eid = 0;


int dfn[maxn + 17], low[maxn + 17], ttl = 1;
std::stack<int> s;
int belong[maxn + 17], belong_ttl = 1;
int indegree_belong[maxn] = {0}, outdegree_belong[maxn] = {0};
bool vis[maxn + 17] = {false};


void tarjan(int u){
    ttl++;
    dfn[u] = low[u] = ttl;
    s.push(u);
    vis[u]= true;
    
    for(int i = heads[u];i; i = edges[i].next){
        const int v = edges[i].to;

        if(!dfn[v]){
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        }else if(vis[v]){
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]){
        int v;
        do{
            v = s.top();
            s.pop();
            belong[v] = belong_ttl;
            vis[v] = false;
        }while( v!= u);
        belong_ttl++;
    }
}
void solve(){
    for(int i = 1; i <= N; i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int u = 1; u <= N; u++){
        for(int i = heads[u]; i; i = edges[i].next){
            const int v = edges[i].to;
            if(belong[v] != belong[u]){
                indegree_belong[belong[v]]++;
                outdegree_belong[belong[u]]++;
            }
        }
    }

    int ans1 = 0, ans2 = 0;
    for(int i = 1; i < belong_ttl; i++){
        if(indegree_belong[i] == 0){
            ans1++;
        }
        if(outdegree_belong[i] == 0){
            ans2++;
        }
    }
    if(belong_ttl == 2) ans2 = 0;
    if(ans2 != 0) ans2 = std::max(ans2, ans1);
    std::cout << ans1 << "\n" << ans2;
}



void add_edge(int u, int v){
    eid++;
    edges[eid].to = v;
    edges[eid].next = heads[u];
    heads[u] = eid;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> N;
    for(int u = 1; u <= N; ){
        int v;
        std::cin >> v;
        if(v==0){
            u++;
            continue;
        }
        add_edge(u, v);
    }
    solve();
    return 0;
}