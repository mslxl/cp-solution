#include<bits/stdc++.h>

bool leading_space = false;
void print(const char* c){
	if(leading_space) std::cout << ' ';
	std::cout << c;
	leading_space = true;
}

void solve(){
	leading_space = false;
	
	int gender, height, weight;
	std::cin >> gender >> height >> weight;
	const int std_height = gender == 1 ? 130 : 129;
	const int std_weight = gender == 1? 27 : 25;
	if(height < std_height){
		print("duo chi yu!");
	}else if(height > std_height){
		print("ni li hai!");
	}else{
		print("wan mei!");
	}
	
	if(weight < std_weight){
		print("duo chi rou!");
	}else if(weight > std_weight){
		print("shao chi rou!");
	}else{
		print("wan mei!");
	}

}
int main(){
	int N;
	std::cin >> N;
	while(N--){
		solve();
		std::cout << std::endl;
	}
}
