#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;
void solve(){
	std::string pwd;
	std::getline(std::cin, pwd);
	if(pwd.size() < 6){
		std::cout << "Your password is tai duan le." << std::endl;
		return;
	}
	bool have_letter = false, have_number = false;
	for(auto& c: pwd){
		if(isalpha(c)){
			have_letter = true;
		}else if(isdigit(c)){
			have_number = true;
		}else if(c != '.'){
			std::cout << "Your password is tai luan le." << std::endl;
			return;
		}
	}
	if(!have_letter){
		std::cout << "Your password needs zi mu." << std::endl;
		return;
	}
	if(!have_number){
		std::cout << "Your password needs shu zi." << std::endl;
		return;
	}
	std::cout << "Your password is wan mei." << std::endl;
}
int main(){
	int q;
	std::cin >> q;
	std::cin.get();
	for(int i = 0; i < q; i++){
		solve();
	}
	
	return 0;
}
