//
//  code.cpp
//  step5
//
//  Created by ljpc on 2018/7/18.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "code.h"

void print(int* beg, int *end){
	std::cout << (*beg);
	beg++;
	while(beg != end){
		std::cout << " " << (*beg);
		beg++;
	}
	std::cout << "\n";
}

void Next_Permutation(int *arr, int n, int m)
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	for(int i= 1; i <= n; i++) arr[i-1] = i;
	while(m--){
		print(arr, arr+n);
		std::next_permutation(arr, arr + n);
	}
	
	/********** End **********/
}

void Prev_Permutation(int *arr, int n, int m)
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	for(int i = 1; i <= n; i++) arr[i-1] = n - i + 1;
	while(m--){
		print(arr, arr+n);
		std::prev_permutation(arr, arr+n);
	}
	/********** End **********/
}

