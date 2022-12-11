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

int get_radix(int num, int l){
    for(int i  = 1; i < l ;i ++){
        num /= 10;
    }
    return num % 10;
}

int* sort_array(int *arr, int n)
//  编程实现《基数排序算法》
//  函数参数：乱序整数数组 数组长度
//  函数返回值：返回从小到大排序后的数组
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    // 上次写 radix sort 还是 suffix array :(
    const int maxn = 1 << 8; 
    int *y = new int[maxn];  // 临时空间
    int *cnt = new int[maxn];
    int bit_mask = maxn - 1;
    for (int i = 0; i < 32; i += 8) {
        for (int j = 0; j != (1 << 8); j++){
            cnt[j] = 0;
        }
        for (int j = 0; j != n; ++j){
            ++cnt[arr[j] >> i & bit_mask];
        }
        for (int sum = 0, j = 0; j != (1 << 8); ++j) {
            sum += cnt[j], cnt[j] = sum - cnt[j];
        }
        for (int j = 0; j != n; ++j){
            y[cnt[arr[j] >> i & bit_mask]++] = arr[j];
        }
        std::swap(arr, y);
    }
    return arr;

    /********** End **********/
}


