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

void sort_array(int *arr, int n)
//  编程实现《插入排序算法》：将乱序序列arr转化为升序序列
//  函数参数：乱序整数数组（无重复元素） 数组长度
//  要求输出：调用print_array(int *arr, int n)输出前三次插入操作后的序列，以及最终的升序序列
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	for(int i=1; i<n; i++){
        int temp;
		if(arr[i] < arr[i-1]){
			temp = arr[i];
            int j = i - 1;
			for(;j >= 0 && arr[j] > temp; --j){
				arr[j+1]=arr[j];
			}
			arr[j+1] = temp;
		}
        if(i < 4){
            print_array(arr,n);
        }
	}
    print_array(arr,n);
    /********** End **********/
}


