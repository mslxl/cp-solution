#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
int N,S;
const int maxn = 1e5 + 17, maxs = 1e2 + 17;

int box_id[maxn];
int item_id[maxn];

int box_content[maxn];

int main(){
	std::cin >> N >> S;
	std::fill_n(box_content, maxn, -1);
	rep(i, 0, N) std::cin >> box_id[i];
	std::stack<int> loads;
	int current_idx = 0;
	rep(i, 0, N/S){
		rep(j, 0, S){
			int num;
			std::cin >> num;
			loads.push(num);
		}
		rep(j, 0, S){
			int item = loads.top();
			loads.pop();
			box_content[box_id[current_idx]] = item;
			tout << "Put " << item << " into " << box_id[current_idx] << std::endl;
			current_idx++;
		}
	}
	int K;
	std::cin >> K;
	rep(i, 0, K){
		int id;
		std::cin >> id;
		if(box_content[id] == -1){
			std::cout << "Wrong Number";
		}else{
			std::cout << box_content[id];
		}
		if(i != K-1) std::cout << std::endl;
	}
}
