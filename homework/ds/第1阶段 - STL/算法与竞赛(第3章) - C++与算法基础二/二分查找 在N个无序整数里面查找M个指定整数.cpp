//
//  main.cpp
//  step1
//
//  Created by ljpc on 2018/7/8.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) 
{
	
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	int T;
	std::cin >> T;
	std::set<int> seq;
	while(T--) {
		int i;
		std::cin >> i;
		seq.insert(i);
	}
	int Q;
	std::cin >> Q;
	while(Q--){
		int a;
		std::cin >> a;
		if(seq.count(a)){
			std::cout << a << " in array\n";
		}else{
			std::cout << a << " not in array\n";
		}
	}
		
	
	/********** End **********/    
	
	return 0;
}

