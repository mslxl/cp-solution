//
//  main.cpp
//  step6
//
//  Created by ljpc on 2018/7/25.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <cctype>

int main(int argc, const char * argv[]) {
	
	
	// 请在这里补充代码，完成本关任务
	/********* Begin *********/
	// 1.创建一个空的键值对映射mp: 键char->值int
	std::map<char ,int> mp;
	
	// 2.读取和处理数据：一行英文句子，长度不超过100，
	std::string line;
	std::getline(std::cin, line);
	for(auto &ch: line){
		if(isalpha(ch)){
			mp[ch]++;
		}
	}
	
	// 3.遍历映射mp，并按指定要求输出
	std::cout << "print map: " << mp.size() << std::endl;
	for(auto &pr: mp){
		std::cout << pr.first << " " << pr.second << std::endl;
	}
	
	// 4.清空mp
	std::cout << 0 << std::endl; //有意义吗?
	
	/********* End *********/
	//printf("%d\n", int(mp.size()));
	
	return 0;
}

