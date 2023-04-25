//
//  code.cpp
//  step2
//
//  Created by ljpc on 2018/7/17.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "code.h"

bool Include_Array(int *arr1, int n1, int *arr2, int n2)
// 函数功能：输入两个升序数组，判断数组arr2是否被包含在数组arr1中（arr2不要求连续，但顺序不能乱）
// 参数介绍：arr1数组一的首地址，n1数组一的个数，arr2数组二的首地址，n2数组二的个数
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	return std::includes(arr1, arr1 + n1, arr2, arr2+n2);
	
	/********** End **********/
}

