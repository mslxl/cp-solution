#include<iostream>

const int maxn = 1e5 + 17;

int num[maxn];
int n = 0;

int dp[maxn];

int q1(){
	dp[0] = 1;
	for(int i = 1; i < n; i++){	
		int biggest_lts_idx = -1;
		for(int j = 0; j < i; j++){
			if(num[j] >= num[i] && dp[j] > dp[biggest_lts_idx]){
				biggest_lts_idx = j;
			}
		}
		if(biggest_lts_idx == -1){
			dp[i] = 1;
		}else{
			//std::cout << num[biggest_lts_idx] << "->" << num[i] << std::endl;
			dp[i] = dp[biggest_lts_idx] + 1; 
		}
		
		//std::cout << "set dp " << i << " " << dp[i] << std::endl;
	}
	int max = -1;
	for(int i = 0; i < n; i++){
		max = std::max(max, dp[i]);
	}
	return max;
}

int missile[maxn] = {INT32_MAX};
int missile_num = 1;

template<typename Iter>
Iter find_min(Iter begin, Iter end, int bigger){
	Iter min_iter = nullptr;
	while(begin != end){
		if((min_iter == nullptr || *min_iter > *begin) && *begin >= bigger){
			min_iter = begin;
		}
		begin++;
	}
	return min_iter==nullptr ? end : min_iter;
}

int q2(){
	const auto beg = missile;
	for(int i = 0; i < n;i++){
		const auto end = missile + missile_num;
		int *iter =  find_min(beg, end, num[i]);
		if(iter != missile + missile_num){
			*iter = num[i];
		}else{
			missile[missile_num++] = num[i]; 
		}
	}
	return missile_num;
}


int main(){
	while(std::cin)
		std::cin >> num[n++];
	n--;
	
	const int v1 = q1();

	const int v2 = q2();
	std::cout << v1 << std::endl << v2;
	return 0;
}
