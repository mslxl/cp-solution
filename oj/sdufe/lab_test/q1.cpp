#include<iostream>
#include<string>

int n;
std::string s;
using ll = unsigned long long;

#define NDEBUG

#ifdef DEBUG
#define dbg(s) std::cout << s << std::endl;
#else
#define dbg(s) do{}while(0)
#endif

// sum interval [l,r)
ll sum_interval(int l, int r){
	ll sum = 0;
	for(int i = l; i < r; i++){
		sum += (s[i] - '0');
	}
	return sum;
}

bool judge(int target_num, int start_index){
	for(int i = start_index; i < s.size(); ){
		for(int j = i+1; j <= s.size(); j++){
			int sum = sum_interval(i, j);
			if(sum > target_num){
				return false;
			}else if(sum == target_num){
				i = j;
				continue;
			}
			if(j == s.size() && sum < target_num){
				return false;
			}
		}
	}
	return true;
}


int main(){
	std::cin >> n;
	std::cin >> s;
	for(int fst_len = 1; fst_len < s.size() - 1; fst_len++){
		int target_num = sum_interval(0, fst_len);
		dbg(target_num);
		if(judge(target_num, fst_len)){
			std::cout << "YES";
			return 0;
		}
	}
	std::cout << "NO";
	return 0;
}
