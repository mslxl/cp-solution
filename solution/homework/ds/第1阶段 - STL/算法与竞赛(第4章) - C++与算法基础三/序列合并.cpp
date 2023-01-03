//
//  code.cpp
//  step1
//
//  Created by ljpc on 2018/7/17.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "code.h"

int* Merge_Array(int *arr1, int n1, int *arr2, int n2)
// 函数功能：合并两个数组arr1和arr2，完成升序排序，返回排序后的合并数组
// 参数介绍：arr1数组一的首地址，n1数组一的个数，arr2数组二的首地址，n2数组二的个数
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	std::sort(arr1, arr1+n1);
	std::sort(arr2, arr2+n2);
	int *ptr = new int[n1+n2];
	std::merge(arr1, arr1 + n1, arr2, arr2+n2, ptr);
	return ptr;
	/********** End **********/
}

