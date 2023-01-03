//
//  sort_.cpp
//  Sort
//
//  Created by ljpc on 2018/4/20.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "sort_.h"
#include <queue>

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


void heapify(int* arr, int l, int r)
{
	int c = arr[l];
	for (int i = 2 * l + 1; i <= r; i = i * 2 + 1){
		if (i < r && arr[i] < arr[i + 1]){
			i++;
		}
		if (arr[i] > c){
			arr[l] = arr[i];
			l = i;
		} else {
			break;
		}
	}
	arr[l] = c;
}

void adjustHeap(int *arr, int param1, int j)
// 编程实现堆的调整
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    /********** End **********/
}

int* heap_sort(int *arr, int n)
//  基于adjustHeap函数编程实现堆排序
//  函数参数：无序数组arr 数组长度n
//  函数返回值：返回从小到大排序后的数组
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    // 众所周知 priority_queue也是堆 :)
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap(arr, arr+n);
    for(int i = 0; i < n; i++){
        arr[i] = heap.top();
        heap.pop();
    }
    return arr;

    /********** End **********/
}

