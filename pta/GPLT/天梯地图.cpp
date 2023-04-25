#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

int N, M;
const int maxn = (500 + 17) * 2 + 1;
int pt_start, pt_end;
struct Edge{
	int next;
	int to, length, time;
};
Edge *nodes = nullptr;
int head[maxn] = {0}, eid = 0;

void add_edge(int from, int to, int length, int time){
	eid++;
	nodes[eid].to = to;
	nodes[eid].length = length;
	nodes[eid].time = time;
	nodes[eid].next = head[from];
	head[from] = eid;
}

void read_data(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> N >> M;
	nodes = new Edge[M+ 17];
	std::memset(nodes, 0, sizeof(Edge) * (M+ 17));
	
	rep(i, 0, M){
		int v1, v2, oneWay, length, time;
		std::cin >> v1 >> v2 >> oneWay >> length >> time;
		add_edge(v1, v2, length, time);
		if(!oneWay){
			add_edge(v2, v1, length, time);
		}
	}
	std::cin >> pt_start >> pt_end;
}


std::pair<std::vector<int>, int> djisktra(const int start,
						const int end,
						std::function<int(const Edge&)> accessor){
	struct Record{
		int depth;
		int weight;
		int point;
		int from;
		Record(int point, int depth, int weight,int from): point(point), depth(depth),weight(weight),from(from){
			
		};
		bool operator <(const Record & rhs) const {
			if(this->weight == rhs.weight){
				return this->depth > rhs.depth;
			}else{
				return this->weight > rhs.weight;
			}
		}
	};	

	test std::cout << "--------------" << std::endl;
	int parent[maxn] = {-1};
	int depth_of_parent[maxn] = {-1};
	bool vis[maxn];
	std::memset(parent, -1, sizeof(parent));
	std::memset(depth_of_parent, -1, sizeof(parent));
	std::memset(vis, false, sizeof(vis));
	
	vis[start] = true;
	// pair<target, weight>
	std::priority_queue<Record> *best_edge = new std::priority_queue<Record>();
	for(int node_id = head[start]; node_id != 0; node_id = nodes[node_id].next){
		const int v = nodes[node_id].to;
		best_edge->push(Record(v, 1, accessor(nodes[node_id]), start));
	}
	int min_weight;
	while(!best_edge->empty()){
	
		const auto edge = best_edge->top();
		best_edge->pop();
		if(depth_of_parent[edge.point] == -1 || depth_of_parent[edge.point] > edge.depth){
			parent[edge.point] = edge.from;
			depth_of_parent[edge.point] = edge.depth;
		}
		
		test std::cout << "Pop " << edge.point << " , weight " << edge.weight << std::endl;
		const int u = edge.point;
		if(u == end){
			min_weight = edge.weight;
			break;
		}
	
		vis[u] = true;
		for(int node_id = head[u]; node_id != 0; node_id = nodes[node_id].next){
			const int v = nodes[node_id].to;
			if(!vis[v]){
				test std::cout << "Push " << v << " , weight " << (accessor(nodes[node_id]) + edge.weight) << std::endl;
 				best_edge->push(Record(v, edge.depth + 1, accessor(nodes[node_id])+ edge.weight, u));
			}
		}
	}
	
	std::vector<int> result;
	int location = end;
	result.push_back(location);
	while(location != start){
		location = parent[location];
		result.push_back(location);
	}
	std::reverse(result.begin(), result.end());
	return std::make_pair(result,min_weight);
}


template<typename Iter>
void print_route(Iter begin, Iter end){
	if(begin == end) return;
	
	std::cout << *begin;
	while(++begin != end){
		std::cout << " => " << *begin;
	}
}

int main(){
	read_data();
	
	auto best_time = djisktra(pt_start, pt_end, [](const Edge& e)->int{
		return e.time;
	});
	
	auto best_length = djisktra(pt_start, pt_end, [](const Edge& e)->int{
		return e.length;
	});
	
	
	if(best_time.first != best_length.first){
			std::cout << "Time = " << best_time.second;
		std::cout << ": " ;
		print_route(best_time.first.begin(), best_time.first.end());
		std::cout << std::endl;
	
		std::cout << "Distance = "<< best_length.second;
		std::cout << ": ";
		print_route(best_length.first.begin(), best_length.first.end());
	}else{
		std::cout << "Time = " << best_time.second << "; Distance = " << best_length.second << ": ";
		print_route(best_length.first.begin(), best_length.first.end());
		
	}

	
	return 0;
}

