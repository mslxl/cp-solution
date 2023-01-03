//
//  binary_sort_tree.cpp
//  BinarySortTree
//
//  Created by ljpc on 2018/5/11.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "binary_sort_tree.h"

BiTreeNode* insertBiSortTree(BiTreeNode* root, int key)
// 功能：实现向升序二叉排序树插入元素
// 输入：待插入元素key
// 返回：升序二叉排序树根节点
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if(root->data == key){
		return root; //
	} else if(root->data > key) {
		if(root->left == nullptr) {
			root->left = (BiTreeNode*) malloc(sizeof(BiTreeNode));
			root->left->right = root->left->left = nullptr;
			root->left->data = key;
		}else{
			insertBiSortTree(root->left, key);
		}
	} else  {
		if(root->right == nullptr) {
			root->right = (BiTreeNode*)malloc(sizeof(BiTreeNode));
			root->right->right = root->right->left = nullptr;
			root->right->data = key;
		}else{
			insertBiSortTree(root->right, key);
		}
	}
	return root;
	/********** End **********/
}

BiTreeNode* creatBiSortTree(int* arr, int n)
// 功能：实现创建升序二叉排序树
// 输入：无序整数数列arr，数列个数n
// 返回：升序二叉排序树根节点
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	BiTreeNode* root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	root->left = root->right = nullptr;
	root->data = arr[0];
	for(int i = 1; i < n ; i++){
		insertBiSortTree(root, arr[i]);
	}
	return root;
	/********** End **********/
}


