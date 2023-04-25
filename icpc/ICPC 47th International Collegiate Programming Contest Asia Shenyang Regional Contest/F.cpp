#include<bits/stdc++.h>
#define pr(a,b) std::make_pair(a,b)

std::map<std::pair<int,int>, std::string> c;

int main(){
	int T;
	std::cin >> T;
	
	c[pr(1,4)] = "0 1 1 0";
	c[pr(4,1)] = "0\n1\n1\n0";
	c[pr(1,3)] = "0 1 0";
	c[pr(3,1)] = "0\n1\n0";
	c[pr(2,3)] = "0 1 1\n1 1 0";
	c[pr(3,2)] = "0 1\n1 1\n1 0";
	
	while(T--){
		int n,m;
		std::cin >> n >> m;
		if(c.count(pr(n,m))){
			std::cout << "Yes\n" << c[pr(n,m)] << std::endl;
		}else{
			std::cout << "No\n";
		}
	}
	return 0;
}
