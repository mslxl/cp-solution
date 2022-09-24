//
//  main.cpp
//  step5
//
//  Created by ljpc on 2018/7/25.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
	
	
	// 请在这里补充代码，完成本关任务
	/********* Begin *********/
	// 1.创建一个空的键值对映射mp: 键string->值int
	std::map<std::string, int> mp;
	
	// 2.读取和处理数据：插入n个学生信息（姓名 成绩），并按指定要求输出
	int n;
	std::cin >> n;
	while(n--){
		std::string trash, name;
		int sco;
		std::cin >> trash >> name >> sco;
		if(mp.count(name)){
			std::cout << name << " has been recorded" << std::endl;
		}else{
			mp[name] = sco;
		}
	}
	
	// 3.读取和处理数据：删除m个学生信息（姓名），并按指定要求输出
	int m;
	std::cin >> m;
	while(m--){
		std::string trash, name;
		std::cin >>trash >> name;
		if(!mp.count(name)){
			std::cout << name << " has not been recorded" << std::endl;
		}else{
			mp.erase(name);
		}
	}
	
	// 4.遍历映射mp，并按指定要求输出
	std::cout << "print map: " << mp.size() << std::endl;
	for(auto& pr: mp)
		std::cout << pr.first << " " << pr.second << std::endl;
	
	// 5.查找q个学生信息，并按指定要求输出
	int q;
	std::cin >> q;
	while(q--){
		std::string trash, name;
		std::cin >> trash >> name;
		if(mp.count(name)){
			std::cout << name << " score " << mp[name] << std::endl;
		}else{
			std::cout << name << " cannot been found" << std::endl;
		}
	}
	
	// 6.清空集合
	std::cout << 0 << std::endl;
	/********* End *********/
	//printf("%d\n", int(mp.size()));
	
	return 0;
}

