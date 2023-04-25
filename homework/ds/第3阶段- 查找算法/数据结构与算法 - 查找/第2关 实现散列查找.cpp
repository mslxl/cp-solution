#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "indLnkHash.h"

LHTable* ILH_Create(int n)
//创建散列表, n为表长度，最佳取值：n取小于等于数据个数的最大质数
{
	HNode* pn=(HNode*)malloc(sizeof(HNode)*n);
	for (int i=0; i<n; i++) {
		pn[i].key=0;
		pn[i].next=NULL;
	}
	LHTable* pt=(LHTable*)malloc(sizeof(LHTable));
	pt-> pn=pn;
	pt->n=n;
	return pt;
}

void ILH_Free(LHTable* pt)
//释放散列表
{
	if (pt==NULL) return;
	for (int i=0; i<pt->n; i++) {
		HNode* curr=pt->pn[i].next;
		while (curr) {
			HNode* next=curr->next;
			free(curr);
			curr=next;
		}
	}
	free(pt->pn);
	free(pt);
}

bool ILH_InsKey(LHTable* pt, int x)
//插入关键码x
//返回true，表示插入成功
//返回false，表示插入失败(关键码已经存在)
{
	/*请在BEGIN和END之间实现你的代码*/
	/*****BEGIN*****/
	int d=x%pt->n;
	if (pt->pn[d].key==0) {
		pt->pn[d].key=x;
		return true;
	} else {
		
		if(pt->pn[d].key == x) return false;
		HNode* curr=&(pt->pn[d]);
		while (curr->next != nullptr){
			curr=curr->next;
			if(curr->key==x){
				return false;
			}
		} 
		curr->next = (HNode*)malloc(sizeof(HNode));
		curr = curr->next;
		curr->next = nullptr;
		curr->key = x;
		return true;
	}
	/******END******/
	/*请不要修改[BEGIN,END]区域外的代码*/
}

bool ILH_FindKey(LHTable* pt, int x)
//查找关键码x
//返回true表示找到
//返回false表示没找到
{
	int d=x%pt->n;
	if (pt->pn[d].key==0) {
		return false;
	}
	else if (pt->pn[d].key==x) 
		return true;
	
	HNode* curr=pt->pn[d].next;
	while (curr && curr->key!=x) curr=curr->next;
	
	if (curr) return  true;
	else return false;
}

bool ILH_DelKey(LHTable* pt, int x)
//删除关键码
//返回true表示该关键码存在，且成功删除
//返回false表示该关键码不存在
{
	/*请在BEGIN和END之间实现你的代码*/
	/*****BEGIN*****/
	int d=x%pt->n;
	if (pt->pn[d].key==x) {
		if(pt->pn[d].next != nullptr){
			pt->pn[d].key = pt->pn[d].next->key;
			pt->pn[d].next = pt->pn[d].next->next;
		}
		pt->pn[d].key=0;
		return true;
	} else {
		HNode* curr=&(pt->pn[d]);
		while (curr->next != nullptr){
			if(curr->next->key==x){
				curr->next = curr->next->next;
				return true;
			}
			curr=curr->next;
		} 
		return true;
	}
	/******END******/
	/*请不要修改[BEGIN,END]区域外的代码*/
}

void ILH_Print(LHTable *pt)
{
	for (int i=0; i<pt->n; i++) {
		printf("%5d:", i);
		if (pt->pn[i].key) {
			printf("%d", pt->pn[i].key);
			HNode* curr=pt->pn[i].next;
			while (curr) {
				printf("->%d", curr->key);
				curr=curr->next;
			}
			printf("\n");
		}
		else 
			printf("-\n");
	}
}
