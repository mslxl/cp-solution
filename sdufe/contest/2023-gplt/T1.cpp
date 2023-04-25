#include<bits/stdc++.h>
using ll = long long;
using ul = unsigned long long;
void solve();

int main(){
	int t;
	std::cin >> t;
	for(int i = 0; i < t; i++){
		solve();
	}
}
#define int ul
void solve(){
	int n;
	std::cin >> n;
	std::vector<int> q(n);
	for(int i = 0; i < n; i++){
		int a;
		std::cin >> a;
		if(a == 1){
			q[i] = 20;
		}else if(a == 2){
			q[i] = 60;
		}else if(a == 3){
			q[i] = 5 * 60 + 1;
		}
	}
	const int limit = 5*60;
	int max = 0;
	int sum = 0;
	
	for(int i = 0; i < q.size(); i++){
		sum += q[i];
		if(sum <= limit){
			max = std::max(max, i+1);
		}else{
			break;
		}
	}
	sum = 0;
	std::reverse(q.begin(), q.end());
	for(int i = 0; i < q.size(); i++){
		sum += q[i];
		if(sum <= limit){
			max = std::max(max, i+1);
		}else{
			break;
		}
	}

	std::cout << max << "\n";
}
