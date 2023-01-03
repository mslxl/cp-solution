//
//  main.cpp
//  step2
//
//  Created by ljpc on 2018/7/6.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

struct Student{
	int numberID;
	char name[20];
	int score;
	Student(){}
	Student(int id_, char *name_, int score_){
		numberID = id_;
		strcpy(name, name_);
		score = score_;
	}
	void in()
	{
		scanf("%d %s %d", &numberID, name, &score);
	}
	void out()
	{
		printf("%d %s %d\n", numberID, name, score);
	}
};

bool min_cmp(Student S1, Student S2){
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if(S1.score == S2.score){
		return S1.numberID < S2.numberID;
	}else{
		return S1.score < S2.score;
	}
	
	/********** End **********/
}

int main(int argc, const char * argv[]) 
{    
	
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	Student s1,s2;
	s1.in();
	s2.in();
	Student ret = std::min(s1,s2, min_cmp);
	ret.out();
	/********** End **********/
	
	return 0;
}

