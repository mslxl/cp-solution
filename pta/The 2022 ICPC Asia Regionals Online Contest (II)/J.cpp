#include<bits/stdc++.h>

int main(){
	int n;
	std::cin >> n;
	std::vector<int> s(n);
	for(int i = 0 ; i < n; i++) std::cin >> s[i];


	int l = 1, r = 1;
	
	for(int i = 1; i < n; i++){
		if(s[i] > s[i-1]){
			l++;
		}else{
			break;
		}
	}

	for(int i = n-2; i > 0; i--){
		if(s[i] > s[i+1]){
			r++;
		}else{
			break;
		}
	}

	if(l % 2== 0 && r % 2 == 0){
		std::cout << "Bob";
		return 0;
	}
	std::cout << "Alice";

	return 0;
}
