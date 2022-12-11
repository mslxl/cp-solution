#include<string>
/*************************************************************
  date: April 2009
  copyright: Zhu En
  DO NOT distribute this code.
 **************************************************************/

int FindSubStr(char* t, char* p)
/*
  从字符串t查找子字符串p。
  字符串以数值结尾，例如p="str",那么p[0]='s',p[1]='t',p[2]='r',p[3]=0。
  采用朴素的匹配算法。
  返回子字符串第一次出现的位置,例如t="string ring",p="ring"，则返回2。
  若没有找到，则返回-1。
 */
{
	// 请在此添加代码，补全函数FindSubStr
	/********** Begin *********/
	//朴素吗?
	std::string s1(t);
	std::string s2(p);
	return s1.find(s2);
	/********** End **********/
}

