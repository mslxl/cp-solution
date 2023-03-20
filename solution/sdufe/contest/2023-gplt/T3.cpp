#include<bits/stdc++.h>
//#define int long long
int n;
std::set<int> set;
std::vector<int> seq;

////#undef int
int main(){
//#define int long long
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int a;
		std::cin >> a;
		set.insert(a);
		seq.push_back(a);
	}
	for(int i = 0 ; i < seq.size(); i++){
		for(int j = i; j < seq.size(); j++){
			for(int k = j; k < seq.size(); k++){
				int result = seq[i] + seq[j] + seq[k];
				if(set.count(result)){
					std::cout << "Yes";
					//std::cerr << seq[i] << " "  << seq[j]  << " " << seq[k] << "=" << result << std::endl;
					return 0;
				}
			}
		}
	}
	
	std::cout << "No";
	return 0;
}
