#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
const int maxm = 1e5 + 17;
const int maxn = 1e4 + 17;


struct Node{
    int to, next;
} graph[maxm];
int head[maxn] = {0}, eid = 0;
struct
int weight[maxn] = {0};
void add_edge(int u, int v){
    eid++;
    graph[eid].to = v;
    graph[eid].next = head[u];
    head[u] = eid;
}

int scc_head[maxn], scc_eid = 0;

int dfn[maxn], low[maxn];
void tarjan(int u, int order){
    dfn[u] = low[u] = order;
    for(int node_id = head[u]; node_id != 0; node_id = graph[node_id].next){
        const int v = graph[node_id].to;
        if(!dfn[v]){
            tarjan(v, order+1);
            low[u] = std::min(low[u], low[v]);
            // do something related...
        }else{
            low[u] = std::min(low[u], dfn[v]);
        }


        if(low[u] == dfn[v]){
            // the root of
        }
    }

}

int n,m;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n >> m;
    rep(i, 0, n){
        std::cin >> weight[i];
    }
    rep(i, 0, m){
        int u,v;
        std::cin >> u >> v;
        add_edge(u, v);
    }
    rep(i, 1, n+1){

    }
	return 0;
}
