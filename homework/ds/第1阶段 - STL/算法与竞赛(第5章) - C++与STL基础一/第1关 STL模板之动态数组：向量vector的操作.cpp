//
//  main.cpp
//  step1
//
//  Created by ljpc on 2018/7/23.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
	int n;
	std::cin >> n;
	std::vector<int> seq(n);
	for(int i = 0 ; i < n; i++){
		std::cin >> seq[i];
	}
	std::sort(seq.begin(), seq.end());
	auto end = std::unique(seq.begin(), seq.end());
	auto beg = seq.begin();
	std::cout << (*beg);
	beg++;
	while(beg != end){
		std::cout << " " << (*beg);
		beg++;
	}
	std::cout << std::endl << 0;

	
	return 0;
}

