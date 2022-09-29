//Graph
///////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
/////////////////////////////////////////////////////////////
Graph* Graph_Create(int n)
{
	Graph* g=(Graph*)malloc(sizeof(Graph));
	g->n=n;
	g->vetex=(char**)malloc(sizeof(char*)*n);
	int i;
	for (i=0; i<n; i++) g->vetex[i] = NULL;
	g->adj=(int*)malloc(sizeof(int)*n*n);
	int j;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			g->adj[i*n+j]=0;
		}
	}
	return g;
}

void Graph_Free(Graph* g)
{
	free(g->adj);
	int i;
	for (i=0; i<g->n; i++) free(g->vetex[i]);
	free(g->vetex);
	free(g);
}

int Graph_DepthFirst(Graph*g, int start, Edge* tree)
//从start号顶点出发深度优先遍历，（编号从开始）
//返回访问到的顶点数，
//tree[]输出遍历树
//返回的tree[0]是(-1, start), 
//真正的遍历树保存在tree[1..return-1], return是返回值
//顶点的访问次序依次为tree[0].to, tree[1].to, ..., tree[return-1].to
//输入时，tree[]的长度至少为顶点数
//返回值是从start出发访问到的顶点数
{
	/*请在BEGIN和END之间实现你的代码*/
	/*****BEGIN*****/
	const int maxn = 1e5 + 17;
	Edge stack[maxn];
	int top = -1;
	char* visited = (char*)malloc(sizeof(char) * g->n);
	memset(visited, 0, sizeof(char)*g->n);
	int parent = -1;
	int curr = start;
	
	top++;
	stack[top].from = parent;
	stack[top].to = curr;
	int k = 0;
	while (top >= 0) {
		parent = stack[top].from;
		curr = stack[top].to;
		top--;
		
		if (visited[curr])
			continue;
		visited[curr] = 1;
		tree[k].from = parent;
		tree[k].to = curr;
		k++;
		for (int j = g->n - 1; j >= 0; j--) {
			if ((g->adj[(curr)*g->n + (j)] == 1) && !visited[j]) {
				top++;
				stack[top].from = curr;
				stack[top].to = j;
			}
		}
	}
	return k;
	/*****END*******/
}
