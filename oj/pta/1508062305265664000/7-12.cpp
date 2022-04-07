#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

int N, M;
int tree[1017];
std::map<int, int> jump_table;

void heapify(int n){
	const int c1 = 2 * n + 1;
	const int c2 = 2 * n + 2;
	int min = n;
	if(c1 < N && tree[c1] < tree[min]){
		min = c1;
	}
	if(c2 < N && tree[c2] < tree[min]){
		min = c2;
	}
	if(min != n){
		std::swap(tree[min], tree[n]);
		heapify(min);
	}
}

void build_heap(){
	const int last_node = N - 1;
	const int h = (last_node - 1) / 2;
	for(int i = h; i >= 0; i--){
		heapify(i);
	}
}

void build_jump_table(){
	rep(i, 0, N){
		jump_table[tree[i]] = i;
	}
}
void trash_line(){
	std::string trash;
	std::getline(std::cin, trash);
}

bool solve(){
	int x,y;
	std::string word;
	std::cin >> x;
	std::cin >> word;
	if(word == "and"){
		// x and y are sibings
		std::cin >> y;
		trash_line();
		test std::cout << "sibing: ";
		return (jump_table[x] - 1) /2 == (jump_table[y] - 1) /2;
		
	}else{
		std::cin >> word;
		if(word == "a"){
			// x is a child of y
			std::cin >> word >> word >> y;
			trash_line();
			test std::cout << "x - y: ";
			return (jump_table[x] - 1) /2 == jump_table[y];
		}else {
			std::cin >> word;
			if(word == "root"){
				// x is the root
				trash_line();
				test std::cout << "root: ";
				return jump_table[x] == 0;
			}else{
				// x is the parent of y
				std::cin >> word >> y;
				trash_line();
				test std::cout << "y - x: ";
				return (jump_table[y] - 1) /2 == jump_table[x];
			}
		}
	}
	assert(false);
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> N >> M;
	
	rep(i, 0, N)
		std::cin >> tree[i];
	build_heap();
	
	test {
		std::cout << "Heap:";
		rep(i, 0, N)
			std::cout << ' ' << tree[i];
		std::cout << std::endl;
	}
	
	
	build_jump_table();
	rep(i, 0, M) {
		std::cout << (solve() ? 'T' : 'F') << std::endl;
	}
	
	
	return 0;
}

