#include<bits/stdc++.h>
using ll = long long;
ll Y;

int main(){
	#define int ll
	std::cin >> Y;
	std::cout << 1 << "\n" << Y << "\n";
	//std::cout << "---------\n";
	std::vector<int> value;
	std::set<int> ans;
	
	int V = Y;
	for(int i = 0; V != 0; i++){
		value.push_back((V&1) << i);
		ans.insert((V&1) << i);
		//std::cerr << "push " << ((V&1) << i) << std::endl;
		V>>=1;
	}
	
	for(int i = 0 ; i < value.size(); i++){
		for(int j  = 0; j < value.size(); j++){
			//std::cerr << "v " << value.size() << ";" << i << ", " << j << ": " << (value[i] | value[j]) << std::endl;
			if(ans.count(value[i] | value[j])){
				continue;
			}
			value.push_back(value[i] | value[j]);
			//std::cerr << "insert " << i << ", " << j << ": " << (value[i] | value[j]) << std::endl;
			ans.insert(value[i] | value[j]);
		}
	}
	ans.insert(0);
	
	std::cout << ans.size() << "\n";
	for(auto i : ans){
		std::cout << i << "\n";
	}
	
	
	return 0;
}
