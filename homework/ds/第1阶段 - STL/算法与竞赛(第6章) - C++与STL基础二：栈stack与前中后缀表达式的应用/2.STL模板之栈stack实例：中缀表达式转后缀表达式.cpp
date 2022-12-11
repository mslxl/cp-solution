// 
//  main.cpp
//  step1
//
//  Created by ljpc on 2018/8/31.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cassert>

bool is_op(const char& c){
	// 看什么看，不是 OP
	return c == '+' || c == '-' || c == '*' || c =='/';
}

int ord_op(const char& ch){
	// 搞成 int, 比大小方便
	switch(ch){
	case '+':
	case '-':
		return 0;
	case '*':
	case '/':
		return 1;
	}
	assert(false); // 寄
}

int main() {
	
	// 请在这里补充代码，完成本关任务
	/********* Begin *********/
	std::stack<char> S1;
	std::stack<char> S2;
	std::string eq;
	std::getline(std::cin, eq);
	
	for(int i = 0; i < eq.size(); i++){
		const char& ch = eq[i];
		
		if(std::isdigit(ch)){
			S2.push(ch);
		}else if(is_op(ch)) {
			again: // :)
			if(S1.empty() || S1.top() == '(') {
				S1.push(ch);
			} else if(ord_op(ch) > ord_op(S1.top())){
				S1.push(ch);
			} else {
				S2.push(S1.top());
				S1.pop();
				goto again;
			}
		}else if(ch == '(' || ch == ')') {
			if(ch == '('){
				S1.push(ch);
			} else {
				while(S1.top() != '('){
					S2.push(S1.top());
					S1.pop();
				}
				S1.pop(); // Trash ')'
			}
		}
	}
	while(!S1.empty()){
		S2.push(S1.top());
		S1.pop();
	}
	std::string output;
	while(!S2.empty()){
		output = S2.top() + output;
		S2.pop();
	}
	std::cout << output;
	
	/********* End *********/   
	
	return 0;
}

