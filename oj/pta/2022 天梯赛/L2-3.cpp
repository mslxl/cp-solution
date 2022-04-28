#include<bits/stdc++.h>
#define rep(i,s,e) for(int i = s; i < e; i++)
const int maxn = 1e5 + 17;
int nodes[maxn];
bool vis[maxn];

int N,  M;
int most_far_node = -1,  most_far = 0;
int total_far = 0;
int track_back(int node) {
	int depth = 0;
	while(!vis[node]) {
		vis[node] = true;
		node = nodes[node];
		depth++;
	}
	return depth;
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> N >> M;
	std::fill_n(vis, maxn,false);
	vis[1] = true;
	rep(i, 1, N + 1) {
		std::cin >> nodes[i];
	}
	rep(i, 0, M) {
		int add;
		std::cin >> add;

		if(!vis[add]) {
			int s = track_back(add);
			if (s > most_far) {
				most_far = s;
				most_far_node = add;
			}
			total_far += 2 * s;
		}

		std::cout << (total_far - most_far) << std::endl;
	}


}
