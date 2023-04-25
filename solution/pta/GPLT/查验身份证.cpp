#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
const int weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char check_mapper[] = {'1','0','X','9','8','7','6','5','4','3','2'};
const int modd = 11;

bool valid(const std::string& str){
	int weight_sum = 0;
	rep(i, 0, str.size() - 1){
		int num = str[i] - '0';
		weight_sum += num * weight[i];
	}
	int avge = weight_sum % modd;
	char check_code = check_mapper[avge];
	//test std::cout << "idx " << avge << "  check code = " << check_code;
	return check_code == str[17];
} 

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	std::cin.get();
	bool illeagal = false;
	std::string line;
	
	rep(i,0, T){
		std::getline(std::cin, line);
		if(!valid(line)){
			std::cout << line << std::endl;
			illeagal = true;
		}
	}
	if(!illeagal){
		std::cout << "All passed";
	}
	return 0;
}

