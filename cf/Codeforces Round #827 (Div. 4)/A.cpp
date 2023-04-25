#include<iostream>

void solve(){
	int a,b,c;
	std::cin >> a >> b >> c;
	if(a + b == c || a + c == b || b + c == a){
		std::cout << "YES" << std::endl;
	}else{
		std::cout << "NO" << std::endl;
	}
}
int main(){
	int T;
	std::cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
