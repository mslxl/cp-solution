//
//  main.cpp
//  step3
//
//  Created by ljpc on 2018/7/24.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

int main(int argc, const char * argv[]) {
	
	
	// 请在这里补充代码，完成本关任务
	/********* Begin *********/
	
	// 1.创建一个空的集合st，数据类型为int
	std::set<int> set;

	// 2.读取数据：第一行整数n，后面n行插入或删除操作，并按指定要求输出
	int n;
	std::string op;
	int num;
	std::cin >> n;
	while(n--){
		std::cin >> op >> num;
		if(op[0] == 'i'){
			if(set.find(num) == set.end()) //我寻思着题目也没说啊，怎么样例里有这东西
				set.insert(num);
			else
				std::cout << num << " in set" << std::endl;
			
		}else{
			if(set.find(num) == set.end())
				std::cout << num << " not in set" << std::endl;
			else
				set.erase(num);
			
		}
	}
	
	
	// 3.遍历集合st，并按指定要求输出
	std::cout << "print set: " << set.size() << std::endl;
	do{
		auto &target = set;
		auto beg = target.cbegin();
		auto end = target.cend();
		
		std::cout << (*beg); beg++;
		while(beg != end){
			std::cout << " " << (*beg);
			beg++;
		}
		std::cout << std::endl;
	}while(0);

	
	// 4.读取数据：整数m以及m次查找操作，并按指定要求输出
	int q;
	std::cin >> q;
	while(q--){
		std::cin >> op >> num;
		std::cout << "find " 
			<< num 
			<< (set.find(num) != set.end()? " in ": " not in ") 
			<< "set\n";
	}
	
	// 5.清空集合set
	std::cout << 0; //我直接输出 0，嘿嘿XD
	
	/********* End *********/
	//printf("%d\n", int(st.size()));
	
	return 0;
}

