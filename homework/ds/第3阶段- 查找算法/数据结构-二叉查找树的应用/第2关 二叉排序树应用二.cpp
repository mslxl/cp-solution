//
//  binary_sort_tree.cpp
//  step2
//
//  Created by ljpc on 2018/6/2.
//  Copyright © 2018年 ljpc. All rights reserved.
//


#include "binary_sort_tree.h"

int* InOrder(BiTreeNode* root, int* arr, int &i)
// 功能：实现升序二叉排序树的中序遍历
// 参数：二叉树根节点root，整数数列arr，起始下标i=0
// 返回：中序遍历数列arr
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	
	if(root->left != nullptr){
		InOrder(root->left, arr, i);
	}
	arr[i++] = root->data;
	if(root->right != nullptr) {
		InOrder(root->right, arr, i);
	}
	return arr;
	/********** End **********/
}

bool isOrder(int* arr, int n)
// 功能：判断数列arr是否升序
// 参数：数列arr，数列个数n
// 返回：若升序返回true，否则返回false
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	int last_one = -0x3f3f3f;
	for(int i = 0; i < n; i++){
		if(arr[i] < last_one){
			return false;
		}
		last_one = arr[i];
	}
	return true;
	
	/********** End **********/
}



