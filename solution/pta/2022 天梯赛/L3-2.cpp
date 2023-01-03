#include<bits/stdc++.h>
#define rep(i,s,e) for(int i = s; i < e; i++)

int n,r;
const int maxn = 3 * 1e5 + 17;
const int maxm = maxn;
struct Edge {
	int to, next;
} edges[maxm];
int head[maxn], eid = 0;
bool vis[maxn];
const int modd = 1e9 + 7;
int seqarr[maxn];

void add_edge(int u, int v) {
	eid++;
	assert(eid < maxm);

	edges[eid].to = v;
	edges[eid].next = head[u];
	head[u] = eid;
}
void add_biedge(int u,int v) {
	add_edge(u,v);
	add_edge(v,u);
}
int merge(int left, int right, int* seq) {
	if(left == 0 && right == n-1){
		for(int i = 0; i  < n; i++){
			std::cout << seq[i] << " ";
		}
		std::cout << std::endl;
	}
	if(right == left) return 0;
	if(right - left == 1) {
		if(seq[left] > seq[right]) {
			std::swap(seq[left],seq[right]);
			return 1;
		}
	}
	const int mid = left + (right - left) / 2;

	int left_idx = left, right_idx = mid + 1;
	int inv = 0;
	int arr[right - left + 1];
	
	inv += merge(left, mid,seq);
	inv += merge(mid+1, right, seq);

	for(int i = 0; i < (right - left + 1); i++) {
		if(left_idx <= mid && seq[left_idx] < seq[right_idx]) {
			arr[i] = seq[left_idx];
			left_idx++;
		} else if(right_idx <= right && seq[left_idx] > seq[right_idx]) {
			arr[i] = seq[right_idx];
			right_idx++;
			inv+=(mid -left_idx+1);
		} else {
			if(left_idx <= mid) {
				arr[i] = seq[left_idx];
				left_idx++;
			} else if(right_idx <= right) {
				arr[i] = seq[right_idx];
				right_idx++;
			}
		}
	}
	for(int i = left; i <= right; i++) {
		seq[i] = arr[i - left];
	}
	return inv % modd;
}

int result = 0;

void dfs(const int start, int idx) {
	if(vis[start]) return;
	vis[start] = true;
	
	seqarr[idx] = start;
	std::cout << "set " << idx << " to " << start << std::endl;
	if(idx == n-1){
		int a[n - 1];
		for(int i = 0; i  < n; i++){
			a[i] = seqarr[i];
		}
		result += merge(0, n-1, a);
		result %= modd;
		return;
	}
	
	std::vector<int> selectable;
	
	for(int node_id = head[start]; node_id != 0; node_id = edges[node_id].next) {
		if(vis[edges[node_id].to]) continue;
		selectable.push_back(edges[node_id].to);
	}
	
	std::sort(selectable.begin(), selectable.end());
	
	do{
		int idxx = idx;
		for(const auto& n : selectable){
			idxx++;
			dfs(n, idxx);
		}
	}while(std::next_permutation(selectable.begin(),selectable.end()));
	vis[start] = false;
}



int main() {
	std::cin  >> n >> r;
	rep(i, 1, n) {
		int u,v;
		std::cin >> u >> v;
		add_biedge(u,v);
	}
	dfs(r,0);
	std::cout << result;
}
