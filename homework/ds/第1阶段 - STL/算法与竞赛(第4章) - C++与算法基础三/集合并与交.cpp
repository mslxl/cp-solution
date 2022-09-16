//
//  code.cpp
//  step3
//
//  Created by ljpc on 2018/7/17.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "code.h"

int Set_Union(int *arr1, int n1, int *arr2, int n2, int *arr3)
// 函数功能：给定两个数组arr1和arr2，计算他们的并集，然后存在数组arr3中，并返回并集大小
// 参数介绍：arr1数组一的首地址，n1数组一的个数，arr2数组二的首地址，n2数组二的个数，数组arr3
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	std::sort(arr1, arr1 + n1);
	std::sort(arr2, arr2 + n2);
	return std::set_union(arr1, arr1 + n1, arr2, arr2 + n2, arr3) - arr3;
	
	/********** End **********/
}


int Set_Intersection(int *arr1, int n1, int *arr2, int n2, int *arr3)
// 函数功能：给定两个数组arr1和arr2，计算他们的交集，然后存在数组arr3中，并返回交集大小
// 参数介绍：arr1数组一的首地址，n1数组一的个数，arr2数组二的首地址，n2数组二的个数，数组arr3
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	std::sort(arr1, arr1 + n1);
	std::sort(arr2, arr2 + n2);
	return std::set_intersection(arr1, arr1 + n1, arr2, arr2 + n2, arr3) - arr3;
	
	/********** End **********/
}


