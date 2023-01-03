#include<bits/stdc++.h>
int L, G;

const char* young = "Too Young";
const char* simple = "Too Simple";
const char* naive = "Sometimes Naive";

void solve(int w, int h){
	while(w > G || h > G){
		w/=2;
		h/=2;
	}
	
	if(w < L || h < L){
		std::cout << young << std::endl;
	} else if(w != h){
		std::cout << simple << std::endl;
	} else{
		std::cout << naive << std::endl;
	}
}

int main(){
	int T;
	std::cin >> T >> L >> G;
	while(T--){
		int w,h;
		std::cin >> w >> h;
		solve(w,h);
	}
}
