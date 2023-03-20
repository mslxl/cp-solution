#include<bits/stdc++.h>
void solve();
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int T;
	std::cin >> T;
	for(int i = 0 ; i< T; i++){
		solve();
	}
	return 0;
}

const int maxn = 2e5 + 17;
using ul = unsigned long long;
#define int ul
int a[maxn];
int req[maxn];
int pre[maxn];

void clear(int n){
	for(int i = 0; i < n; i++){
		req[i] = 0;
		pre[i] = 0;
	}
}

void solve(){
	int n ,q;
	std::cin >> n >> q;
	for(int i = 1 ; i <= n; i++){
		std::cin >> a[i];
		req[i] = std::max(req[i-1], a[i]);
		pre[i] = pre[i-1] + a[i];
	}
	for(int i = 0; i < q; i++){
		int k;
		std::cin >> k;
	
		int ans = 0;
		int L = 1, R = n;
		
		while(L <= R){
			int mid = L + (R-L) / 2;
			if(req[mid] > k){
				R = mid - 1;
			}else{
				ans = mid;
				L = mid + 1;
			}
		}
		
		std::cout << pre[ans] << " ";
	}
	clear(n);
	std::cout << std::endl ;
}
