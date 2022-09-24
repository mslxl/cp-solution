//
//  main.cpp
//  step4
//
//  Created by ljpc on 2018/7/25.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <cctype>

int main(int argc, const char * argv[]) {
	
	
	// 请在这里补充代码，完成本关任务
	/********* Begin *********/
	// 1.创建一个空的集合st，数据类型为char
	std::set<char> st;
	
	// 2.读取和处理数据：一行英文句子，长度不超过100
	std::string line;
	std::getline(std::cin, line);
	for(auto &ch: line){
		if(isalpha(ch)){
			st.insert(ch);
		}
	}
	
	// 3.遍历集合st，并按指定要求输出
	std::cout << "print set: " << st.size() << std::endl;
	do{
		auto &target = st;
		auto beg = target.cbegin();
		auto end = target.cend();
		
		std::cout << (*beg); beg++;
		while(beg != end){
			std::cout << " " << (*beg);
			beg++;
		}
		std::cout << std::endl;
	}while(0);
	
	// 4.清空集合
	std::cout << 0  << std::endl; // LOL :)
	/********* End *********/
	//printf("%d\n", int(st.size()));
	
	return 0;
}

