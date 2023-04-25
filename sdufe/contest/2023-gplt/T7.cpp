#include<bits/stdc++.h>

int n,k;


std::unordered_map<int, std::pair<int,int>> kkk;
int main(){
	std::cin >> n >> k;
	std::string operation;
	std::cin >> operation;
	int lx = 0, ly = 0;
	// 1 -> k-1;
	kkk[k] = std::make_pair(lx,ly);
	for(int i = 1; i <= n; i++){
		char op = operation[i-1];
		if(op == 'U') ly++;
		else if(op == 'D') ly--;
		else if(op == 'L') lx--;
		else if(op == 'R') lx++;
		kkk[k+i] = std::make_pair(lx,ly);
		
		if(kkk.count(i)){
			std::pair<int,int> pos = kkk[i];
			if(pos.first == lx && pos.second == ly){
				std::cout << "no";
				return 0;
			}
		}
	}
	std::cout << "yes";
	return 0;
}
