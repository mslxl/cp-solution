//
//  sort_.cpp
//  Sort
//
//  Created by ljpc on 2018/4/20.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "sort_.h"

void print_array(int *arr, int n)
// 打印数组
{
    if(n==0){
        printf("ERROR: Array length is ZERO\n");
        return;
    }
    printf("%d", arr[0]);
    for (int i=1; i<n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int partition_array(int *arr ,int l,int r)
// 编程实现arr[l, r]分区：选定一个基准，左边比基准小，右边比基准大
// 返回基准所处位置
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int x = arr[r];
	int i = l - 1;
	int select_num;
	for (int j = l; j < r; j++) {
		if (arr[j] <= x) {
			i++;
			select_num = arr[i];
			arr[i] = arr[j];
			arr[j] = select_num;
		}
	}
	select_num = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = select_num;
	return i + 1;

    /********** End **********/
}

int* quick_sort(int *arr, int l, int r)
//  基于partition_array函数编程实现快速排序：自上而下的递归方法
//  函数参数：有序数组arr 初始l=0，r=n-1
//  函数返回值：返回从小到大排序后的数组
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (l < r) {
		int base = partition_array(arr, l, r);
		quick_sort(arr, l, base - 1);
		quick_sort(arr, base + 1, r);
	}
    return arr;
    /********** End **********/
}
