/*************************************************************
  date: April 2009
  copyright: Zhu En
  DO NOT distribute this code.
 **************************************************************/
//折半查找的顺序表 实现文件
//每个结点的数据是关键码
//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "BSlist.h"

BSeqList* BSL_Create(int size)
//创建一个顺序表
//与BSL_Free()配对
{
	BSeqList* blist=(BSeqList*)malloc(sizeof(BSeqList));
	blist->pkey = (int*)malloc(sizeof(int)*size);
	blist->max=size;
	blist->len=0;
	return blist;
}

void BSL_Free(BSeqList* blist)
//释放/删除顺序表
//与BSL_Create()配对
{
	free(blist->pkey);
	free(blist);
}

int BSL_FindKey(BSeqList* blist, int key)
//在排序的顺序表中查找关键码值为key的结点，返回结点的编号
//返回值大于等于0时表示找到值为key的结点的编号，-1表示没有找到
{
	/*请在BEGIN和END之间实现你的代码*/
	/*****BEGIN*****/
	// 你给我10s欸，朴素查找都能跑
	if(blist->len == 0) return -1;
	std::size_t left = 0, right = blist->len -1;
	printf("%d\n", right);
	while(left < right){
		const std::size_t mid = left + (right - left) / 2;
		const int value = blist->pkey[mid];
		if(value==key){
			return mid;
		}else if(key > value){
			left = mid;
		}else{
			right = mid;
		}
	}
	if(blist->pkey[left] == key){
		return left;
	}
	return -1;
	/******END******/
	/*请不要修改[BEGIN,END]区域外的代码*/
}

int BSL_InsKey(BSeqList* blist, int key)
//在排序的顺序表中插入一个值为key的结点
//返回值大于等于0时表示插入的位置, -1表示表满（无法插入）
{
	
	if (blist->len>=blist->max) return -1;
	
	int k, r, m;
	k=0; r=blist->len-1;
	
	//寻找插入位置
	while (k<=r) {
		m=(k+r)>>1; //m=(k+r)/2
		if (key == blist->pkey[m]) return -2;////若不允许插入已存在的值，则需要此行
		if (key<blist->pkey[m])  r=m-1;
		else k=m+1;
	}
	
	//插入位置为k, 腾出k号位置
	for (r=blist->len; r>k; r--) 
		blist->pkey[r]=blist->pkey[r-1];
	//key放入k号位置
	blist->pkey[k]=key;
	blist->len++;
	return k;
}

int BSL_DelKey(BSeqList* blist, int key)
//在排序的顺序表中删除值为key的结点, 
//存在值为x的结点则返回结点编号, 未找到返回－1
{
	int k=BSL_FindKey(blist, key);
	if (k<0) return -1;
	int i=k;
	while(i < blist->len-1) {
		blist->pkey[i] = blist->pkey[i+1];
		i++;
	}
	blist->len --;
	return k;
}

void BSL_Print(BSeqList* blist)
//打印整个顺序表
{
	if (blist->len==0) {
		printf("The list is empty.\n");
		return;
	}
	printf("The list contains: ");
	for (int i=0; i<blist->len; i++) {
		printf("%d  ", blist->pkey[i]);
	}
	printf("\n");
}
