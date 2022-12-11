//
//  main.cpp
//  step1
//
//  Created by ljpc on 2018/9/13.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using ll = unsigned long long;

ll n,m;
ll sum = 0;
std::queue<ll> que;

std::size_t len = 0x3f3f3f;

int main(int argc, const char * argv[]) {
	
	// 请在这里补充代码，完成本关任务
	/********* Begin *********/
	std::cin >> n >> m;
	for(int i = 0; i < n; i++){
		ll num;
		std::cin >> num;
		que.push(num);
		sum+=num;
		while(sum >= m){
			if(que.size() < len){
				len = que.size();
			}
			ll num_rem = que.front();
			que.pop();
			sum -= num_rem;
		}
	}
	if(len == 0x3f3f3f){
		std::cout << 0;
	}else{
		std::cout << len;
	}
	
	/********* End *********/
	
	return 0;
}

