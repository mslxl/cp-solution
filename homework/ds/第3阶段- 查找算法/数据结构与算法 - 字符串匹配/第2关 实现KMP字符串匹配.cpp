/*************************************************************
  date: 
  copyright: Zhu En
  DO NOT distribute this code without my permission.
 **************************************************************/
//字符串 实现文件
//////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "kmp.h"
/////////////////////////////////////////////////////

void KmpGenNext(char* p, int* next)
//生成p的next数组, next数组长度大于等于字符串p的长度加1
{
	// 请在此添加代码，补全函数KmpGenNext
	/********** Begin *********/
	int j =0, k = -1;
	next[0] = -1;
	while(p[j] != '\0'){
		if(k == -1 || p[j] == p[k]){
			next[++j] = ++k;
		}else{
			k = next[k];
		}
	}
	/********** End   *********/
}


int KmpFindSubWithNext(char* t, char* p, int* next)
//从t中查找子串p的第一次出现的位置
//若找到，返回出现的位置，否则返回-1
{
	int i=0, j=0;
	while(p[i]!=0 && t[j]!=0)	{
		if(p[i]==t[j]) 	{ 
			i++;  
			j++; 
		}
		else  if (next[i]>=0) {
			i = next[i];
		}
		else  { 
			i=0;  
			j++; 
		}
	}
	if(p[i]==0)  return j-i; //found
	else  return -1;  //not found
}


