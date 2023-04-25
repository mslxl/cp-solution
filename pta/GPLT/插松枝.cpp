#include<bits/stdc++.h>
#define rep(i,s,e) for(int i = s; i < e; i++)

int N, M, K;
int main() {
	std::cin >> N >> M >> K;
	std::stack<int> box;
	std::queue<int> brunch;
	std::vector<int> warden(N+17);
	rep(i, 0, N) std::cin >> warden[i];


	bool need_clear = false;
	int last_load = 0x3f3f3f;
	int cur_use = 0;
	while(true) {
		if(brunch.size() == K || need_clear) {
			last_load = 0x3f3f3f;
			std::cout << brunch.front();
			brunch.pop();
			while(!brunch.empty()) {
				std::cout << " " << brunch.front();
				brunch.pop();
			}
			std::cout << std::endl;
			need_clear = false;
			continue;
		}

		if (cur_use >= N && box.empty()) break;

		if(!box.empty()  ) {
			if(box.top() <= last_load) {
				brunch.push(box.top());
				last_load = box.top();
				box.pop();
				continue;
			}else if(cur_use >= N){
				need_clear = true;
				continue;
			}
		}

		if (cur_use < N && warden[cur_use] <= last_load) {
			brunch.push(warden[cur_use]);
			last_load = warden[cur_use];
			cur_use++;
			continue;
		} else {
			if(box.size() < M) {
				box.push(warden[cur_use]);
				cur_use++;
				continue;
			} else {
				need_clear = true;
				continue;
			}
		}
	}

	if(!brunch.empty()) {
		std::cout << brunch.front();
		brunch.pop();
		while(!brunch.empty()) {
			std::cout << " " << brunch.front();
			brunch.pop();
		}
	}
}
