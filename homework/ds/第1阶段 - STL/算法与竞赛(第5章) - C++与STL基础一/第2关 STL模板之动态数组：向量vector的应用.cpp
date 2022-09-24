#include<bits/stdc++.h>
 
template<typename T>
std::ostream& operator<< (std::ostream& os, std::vector<T> seq){
	if(seq.empty()){
		os << "0 0";
	}else{
		unsigned long long sum = 0;
		for(auto& item: seq){
			sum += item;
			os << item << " ";
		}
		os << sum;
	}
	return os;
}

int main(){
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> stock(n);
	for(int i = 0; i < n; i++){
		auto &s = stock[i];
		int m;
		std::cin >> m;
		for(int i = 0; i < m; i++){
			int c;
			std::cin >> c;
			s.push_back(c);
		}
	}
	
	int op_cnt;
	std::cin >> op_cnt;
	std::string trash;
	int x,y;
	while(op_cnt--){
		std::cin >> trash >> x >> y;
		if(!stock[x].empty()){
			stock[y].push_back(stock[x].back()), stock[x].pop_back();
		}
	}
	for(std::size_t i = 0; i < stock.size(); i++){
		std::cout << i << " "<< stock[i] << std::endl;
	}
	return 0;
}
