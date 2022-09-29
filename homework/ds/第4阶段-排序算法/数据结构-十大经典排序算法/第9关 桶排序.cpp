//
//  sort_.cpp
//  Sort
//
//  Created by ljpc on 2018/4/20.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "sort_.h"
#include <map>

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


int* sort_array(int *arr, int n)
//  编程实现《桶排序算法》
//  函数参数：乱序整数数组 数组长度
//  函数返回值：返回从小到大排序后的数组
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    // ???? 我好像把上一个当成桶排了
    // 直接复制过来了
    std::map<int,int> bucket; // 又没给数据范围，笑不活了
    for(int i = 0; i < n; i++){
        bucket[arr[i]]++;
    }

    int idx = 0;
    for(auto pr: bucket){
        for(int i = 0; i < pr.second; i++){
            arr[idx++] = pr.first;
        }
    }
    //print_array(arr, n);
    return arr;
    
    
    /********** End **********/
}


