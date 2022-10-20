const int maxn = 1e6; //顶点数
const int maxm = 2e6; //边数

struct edge{
	int to;
	int next;
}e[maxm * 2 + 1];

int eid = 0;
int head[maxn];

void add_edge(int u,int v){
	eid++;
	edge& ed = e[eid];
	ed.to = v;
	ed.next = head[u];
	head[u] = eid;
}

void add_biedge(int u,int v){
	add_edge(u, v);
	add_edge(v, u);
}