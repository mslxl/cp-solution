#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
#define rep(i,s,e) for(int i = (s); (i) < e; i++)
typedef long long ll;
void solve(){
	std::string l;
	std::getline(std::cin, l);
	tout << "input " << l << std::endl;
	if(l.empty()){
		std::cout << "Y";
		return;
	}
	bool last_is_upper = std::isupper(l[0]);
	char last_c = l[0];
	
	for(int i = 1; i < l.size(); i++){
		const char c = l[i];
		tout << "Process " << c << std::endl;
		if(last_is_upper){
			
			if(std::tolower(last_c) != c && c!= last_c + 1){
				tout << "last is " << last_c << ", cur is " << c << std::endl;
				std::cout << "N";
				return;
			}
		}else{
			
			if(std::toupper(last_c) != c && c!= last_c - 1){
				tout << "last is " << last_c << ", cur is " << c << std::endl;
				std::cout << "N";
				return;
			}
		}
		last_is_upper = std::isupper(c);
		last_c = l[i];
	}
	std::cout << "Y";
}
int main(){
	int N;
	std::cin >> N;
	std::string l;
	std::getline(std::cin, l);
	while(N--){
		solve();
		if(N!= 0) std::cout << std::endl;
	}
}
