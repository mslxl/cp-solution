//最短路计数
#include <algorithm>
#include<bits/stdc++.h>
const int maxn = 1e6 + 17;
const int maxm = 2e6 + 17;
const int modd = 100003;

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

int N,M;

bool vis[maxn];
int distance[maxn] = {INT32_MAX};
int distance_num[maxn];

void count(int start){
	std::queue<int> seq;
	std::fill(distance, distance+maxn, INT32_MAX);
	seq.push(start);
	distance[start] = 0;
	distance_num[start] = 1;

	while(!seq.empty()){
		const int u = seq.front();
		seq.pop();
		if(vis[u]) continue;
		vis[u] = true;		

		for(int i = head[u]; i; i = e[i].next){
			const int v = e[i].to;
			if(vis[v]) continue;
			seq.push(v);
			if(distance[v] > distance[u] + 1){
				distance[v] = distance[u] + 1;
				distance_num[v] = distance_num[u];
			}else if(distance[v] == distance[u] + 1){
				distance_num[v]+= distance_num[u];
			}
			distance_num[v] %= modd;	
		}
	}
}


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> N >> M;

	for(int i = 0; i < M; i++){
		int x,y;
		std::cin >> x >> y;
		add_biedge(x, y);
	}
	count(1);
	for(int i = 1; i <= N; i++){
		std::cout << distance_num[i] << std::endl;
	}

	return 0;
}