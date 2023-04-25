#include<bits/stdc++.h>
using namespace std;
const int MAX = 1020, INF = 999999;
int graph[MAX][MAX], visited[MAX], dist[MAX];
int n, m, k, Ds, Dist;
struct Dustbin {
	string id;
	double minDs, aveDs;
	bool operator<(const Dustbin &other) {
		return minDs != other.minDs ? minDs > other.minDs:aveDs != other.aveDs ? aveDs < other.aveDs : id < other.id;
	}
};
void Dijsktra(int dustbin) {
	memset(dist, INF, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	dist[dustbin] = 0;
	for (int i = 1; i <= n + m; i++) {
		int u = -1, min = INF;
		for (int j = 1; j <= n + m; j++) {
			if (!visited[j] && dist[j] < min) {
				min = dist[j];
				u = j;
			}
		}
		if (u == -1)
			return;
		visited[u] = 1;
		for (int j = 1; j <= n + m; j++) 
			if (!visited[j] && dist[j] > dist[u] + graph[u][j])
				dist[j] = dist[u] + graph[u][j];	
	}
}
int main() {
	char a[5], b[5];
	int p1, p2;
	scanf("%d%d%d%d", &n, &m, &k, &Ds);
	memset(graph, INF, sizeof(graph));
	for (int i = 0; i < k; i++) {
		scanf("%s%s%d", &a, &b, &Dist);
		p1 = a[0] == 'G' ? n + atoi(&a[1]) : atoi(a);
		p2 = b[0] == 'G' ? n + atoi(&b[1]) : atoi(b);
		graph[p1][p2] = graph[p2][p1] = Dist;
	}
	Dustbin min;
	for (int i = 1; i <= m; i++) {
		Dijsktra(n + i);
		double sum = 0, minds = dist[1];
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			sum += dist[i];
			if (dist[i] > Ds) flag = 1;
			minds = dist[i] < minds ? dist[i] : minds;
		}
		if (!flag && (min.id.empty() || Dustbin({ "G" + to_string(i),minds,sum / n }) < min))
			min = { "G" + to_string(i),minds,sum / n };
	}
	if (min.id.empty())
		printf("No Solution");
	else 
		printf("%s\n%.1lf %.1lf", min.id.c_str(), min.minDs, min.aveDs);
	return 0;
}