//
//  main.cpp
//  step3
//
//  Created by ljpc on 2018/8/31.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>

#include <string>
#include <cctype>
#include <cassert>
int main() {
	
	// 请在这里补充代码，完成本关任务
	/********* Begin *********/
	std::string eq;
	std::getline(std::cin, eq);
	
	std::stack<int> num;
	
	for(const auto& ch: eq) {
		if(std::isdigit(ch)){
			num.push(ch - '0');
		}else{
			int v2 = num.top(); num.pop();
			int v1 = num.top(); num.pop();
			if(ch == '+'){
				num.push(v1+v2);
			}else if(ch == '-'){
				num.push(v1-v2);
			}else if(ch == '*'){
				num.push(v1*v2);
			}else if(ch == '/'){
				num.push(v1/v2);
			}else{
				assert(false); // Ge
			}
		}
	}
	std::cout << num.top();
	
	/********* End *********/
	
	return 0;
}

