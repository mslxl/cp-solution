#include<bits/stdc++.h>
void solve();
int main(){
	solve();
	return 0;
}
using ll = long long;
const int maxn = 1e5 + 17;
#define int ll
int n,x;
int a[maxn], prefix[maxn];
void solve(){
	std::cin >> n >> x;
	for(int i = 1; i <= n; i++){
		std::cin >> a[i];
		prefix[i] = prefix[i-1] + a[i];
	}
	int max = 0;
	
	int i = 1, j = 1;
	while(true){
		if(prefix[j] - prefix[i-1] <= x){
			max = std::max(max, prefix[j] - prefix[i-1]);
			j++;
		}else{
			i++;
		}
		if(j > n){
			break;
		}
	}
	std::cout << max;
}
