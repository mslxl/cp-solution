#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
int n, m;
const int maxn = 2 * 1e4 + 17;
const int maxm = 1 * 10e5 + 17;

struct Node{
	int to, next;
} nodes[maxm];
int head[maxn] = {0}, eid = 0;
void add_edge(int u, int v){
	eid++;
	nodes[eid].to = v;
	nodes[eid].next = head[u];
	head[u] = eid;
}

void add_biedge(int u, int v){
	add_edge(u,v);
	add_edge(v,u);
}
std::set<int> cut_vert;

int dfn[maxn], low[maxn], root;
void tarjan(int u, int fn, int father_of_u){
	low[u] = dfn[u] = fn;
    int cnt_satify = 0;
	for(int node_id = head[u]; node_id != 0; node_id = nodes[node_id].next){
		const int v = nodes[node_id].to;
		if(v == father_of_u) continue;
        if(!dfn[v]){
            tarjan(v, fn + 1, u);
            low[u] = std::min(low[v], low[u]);
            if(low[v] >= dfn[u]){
                cnt_satify++;
                if(root != u || cnt_satify >= 2){
                    cut_vert.insert(u);
                }
            }
        }else{
            low[u] = std::min(low[u], dfn[v]); // why?
        }
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n >> m;
	rep(i, 0, m){
		int x,y;
		std::cin >> x >> y;
		add_biedge(x,y);
	}
	rep(i, 1, n + 1){
	    if(!dfn[i]){
            // unvisited
            root = i;
            tarjan(i, 1, i);
	    }
	}
	if(cut_vert.empty()){
        std::cout << 0;
	}else{
        std::cout << cut_vert.size() << std::endl;

        for(const auto item : cut_vert){
            std::cout << item << ' ';
        }
	}

	return 0;
}

