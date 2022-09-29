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

int* merge_array(int *arr1, int n1, int* arr2, int n2)
//  编程实现两个有序数组arr1和arr2合并
//  函数参数：有序数组arr1 数组arr1长度 有序数组arr2 数组arr2长度
//  函数返回值：返回从小到大排序后的合并数组
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int *output = new int[n1 + n2];
    std::merge(arr1, arr1+n1, arr2, arr2 + n2, output);
    return output;
    /********** End **********/
}
int* merge_sort(int *arr, int n)
//  基于merge_array函数编程实现归并排序：自上而下的递归方法
//  函数参数：有序数组arr 数组arr长度
//  函数返回值：返回从小到大排序后的数组
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    // :)
    std::sort(arr, arr+n);
    return arr;
    /********** End **********/
}


