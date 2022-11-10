#include<bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
#define int ll
ll n,d;
const int maxn = 5000 + 17;
ll seq[maxn];
ll seq_min = std::numeric_limits<ll>::max(), seq_max = std::numeric_limits<ll>::min();

ull deal(int l, int r){
	ull sum=0;
	auto& a = seq;
	for(int i = 1; i < n; i++){
		ll left = a[i-1] < l? l : a[i-1];
		left = left > r? r : left;
		
		ll right = a[i] < l? l : a[i];
		right = right > r? r : right;
		
		sum += std::abs(left - right);
	}
	return sum;
}

#undef int
int main(){
#define int ll
	std::cin >> n >> d;
	for(int i = 0; i < n; i++){
		std::cin >> seq[i];
		seq_min = std::min(seq[i], seq_min);
		seq_max = std::max(seq[i], seq_max);
	}
	
	if(seq_max - seq_min <= d){
		ull ans = 0;
		for(int i = 1; i < n; i++){
			ans += std::abs(seq[i-1] - seq[i]); 
		}
		std::cout << ans;
		return 0;
	}else{
		ull ans = 0;
		for(int idx = 0; idx < n; idx++){
			int l = seq[idx];
			ans = std::max(ans, deal(l,l + d));
			ans = std::max(ans, deal(l - d, l));
			//std::cerr << "[" << l << ", " << r << "] " << ans << std::endl;
		}
		std::cout << ans;
		return 0;
	}
	
}
