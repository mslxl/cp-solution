#include<bits/stdc++.h>
#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif
#define rep(i,s,e) for(int i = s; i < e; i++)
typedef long long ll;

std::string indent(int i) {
	return std::string(i, ' ');
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);


	std::string line;
	std::getline(std::cin, line);

	int pos = 0, len = 1;
	for(; pos < line.size(); pos += len){
		line.find('{', pos);
	}


	return 0;
}
