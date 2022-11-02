// Crazy Binary String 
#include<iostream>
#include<string>
#include<map>
#include<cmath>

int n;
std::string s;
int main(){
	std::cin >> n;
	std::cin >> s;
	int cnt0 = 0, cnt1 = 0;
	for(const auto& ch : s) {
		if(ch == '0') {
			cnt0++;
		}else if(ch == '1'){
			cnt1++;
		}
	}
	
	int subseq = std::min(cnt1, cnt0) * 2;
	cnt1 = 0;
	std::map<int, int> cnt;
	s = " " + s;
	cnt[0] = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == '1') {
			cnt1++;
		} else {
			cnt1--;
		}
		if(cnt.count(cnt1)) {
			ans = std::max(ans, i - cnt[cnt1]);
		}else{
			cnt[cnt1] = i;
		}
	}
	std::cout << ans << " " << subseq;
	
	return 0;
}
