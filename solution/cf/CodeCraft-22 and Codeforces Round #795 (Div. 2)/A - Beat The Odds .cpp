#include<bits/stdc++.h>
int seq[(int)1e5 + 17];
void solve(){
	int n;
	std::cin >> n;
	int odd = 0;
	for(int i = 0; i < n; i++){
		std::cin >> seq[i];
		if(seq[i] % 2 != 0){
			odd++;
		}
	}
	int even = n - odd;
	std::cout << std::min(even,odd) << std::endl;
}
int main(){
	int n;
	std::cin >> n;
	while(n--){
		solve();
	}
	return 0;
}
