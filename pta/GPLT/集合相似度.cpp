#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;

std::vector<std::set<int>> sets; 

void init(){
	int N;
	std::cin >> N;
	rep(i, 0, N){
		int M;
		std::cin >> M;
		std::set<int> seq;
		rep(j, 0, M){
			int input;
			std::cin >> input;
			seq.insert(input);
		}
		sets.push_back(seq);
	}
}
void compare(int a, int b){
	auto& x = sets[a], y = sets[b];
	std::vector<int> uni, ins;
	std::set_union(
		x.begin(), x.end(),
		y.begin(), y.end(),
	  	std::inserter(uni, uni.begin()));
	std::set_intersection(
		x.begin(),x.end(),
		y.begin(),y.end(),
		std::inserter(ins, ins.begin()));
	printf("%.2lf%%\n", (1.0 * ins.size() / uni.size()) * 100);
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	init();
	int K;
	std::cin >> K;
	rep(i, 0, K){
		int x,y;
		std::cin >> x >> y;
		compare(x-1, y-1);
	}
	return 0;
}

