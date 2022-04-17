#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

const int maxn = 5000 + 17;
const int maxm = 2 * 1e5 + 17;

struct Edge {
	int from, to;
	int length;
	bool operator < (const Edge& rhs )const {
		return this->length < rhs.length;
	}
	Edge rev() const {
		Edge e(*this);
		std::swap(e.from, e.to);
		return e;
	}
};

int parent[maxn], rank[maxn];

int find_root(int u) {
	while (parent[u] != 0) {
		u = parent[u];
	}
	return u;
}

void union_set(int u, int v) {
	int root_u = find_root(u);
	int root_v = find_root(v);
	if (root_v == root_u)
		return;
	if (rank[root_u] > rank[root_v]) {
		parent[root_v] = root_u;
	} else if (rank[root_u] < rank[root_v]) {
		parent[root_u] = root_v;
	} else {
		parent[root_u] = root_v;
		rank[root_v]++;
	}
}

bool is_joint(int u, int v) {
	return find_root(u) == find_root(v);
}

int N, M;
ll kruskal(std::vector<Edge> edges) {
	std::sort(edges.begin(), edges.end());
	ll ans = 0;
	for(const auto& edge: edges){
		const int from = edge.from;
		const int to = edge.to;
		
		if(is_joint(from, to)) continue;
		tout << "Chose " << from << " --> " << to << " (" << edge.length << ")\n";
		ans+=edge.length;
		union_set(from, to);
	}
	return ans;
}


std::istream& operator >> (std::istream& is, Edge & e) {
	return is >> e.from >> e.to >> e.length;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> N >> M;
	std::vector<Edge> edges(M * 2);
	rep(i, 0, M) {
		Edge e;
		std::cin >> e;
		edges.push_back(e);
		edges.push_back(e.rev());
	}
	ll ans = kruskal(edges);
	int root = find_root(1);
	rep(i, 2, N+1){
		if(find_root(i) != root){
			std::cout << "orz";
			return 0;
		}
	}
	std::cout << ans;
	return 0;
}
