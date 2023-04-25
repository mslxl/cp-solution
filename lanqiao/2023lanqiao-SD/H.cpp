#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstring>
#include<queue>
const int maxn = 5e5 + 17;
#define int long long
using elem = std::pair<int,int>;
std::priority_queue<elem, std::vector<elem>, std::greater<elem>> que;
int seq[maxn];
bool seq_remove[maxn];
int leftnear[maxn], rightnear[maxn];

int N, K;


void solve(){
	std::cin >> N >> K;
	for(int i = 1; i <= N; i++){
		std::cin >> seq[i];
		que.push({seq[i], i});
		leftnear[i] = i;
		rightnear[i] = i;
	}
	
	for(int op = 0; op < K; op++){
		elem element = que.top();
		que.pop();
		while(element.first != seq[element.second]){
			// apply modify
			element.first = seq[element.second];
			que.push(element);
			elem element = que.top();
			que.pop();
		}
		seq_remove[element.second] = true;
		
		leftnear[element.second] = leftnear[element.second - 1];
		int l = leftnear[element.second];
		while(leftnear[l] != l) l = leftnear[l];
		leftnear[element.second] = l;
		
		
		rightnear[element.second] = rightnear[element.second + 1];
		int r = rightnear[element.second];
		while(rightnear[r] != r) r = rightnear[r];
		rightnear[element.second] = r;
			
	
		
		
		seq[l] += element.first;
		seq[r] += element.first;
	}
	for(int i = 1; i <= N; i++){
		if(!seq_remove[i]){
			std::cout << seq[i] << " ";
		}
	}
}
#undef int
int main(){
	solve();
	
	return 0;
}

