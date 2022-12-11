//
//  main.cpp
//  step3
//
//  Created by ljpc on 2018/7/6.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
struct Student;
bool max_cmp(Student S1, Student S2);
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
	bool operator < (const Student &S)const
	{
		// 请在这里补充代码，完成本关任务
		/********** Begin *********/
		return max_cmp(*this, S);
		
		/********** End **********/
	}
};

bool max_cmp(Student S1, Student S2)
{
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	if(S1.score == S2.score){
		return S1.numberID < S2.numberID;
	}else{
		return S1.score > S2.score;
	}
	
	/********** End **********/
}

int main(int argc, const char * argv[]) 
{    
	// 请在这里补充代码，完成本关任务
	/********** Begin *********/
	int T;
	std::cin >> T;
	std::vector<Student> seq(T);
	for(int i = 0; i < T; i++) seq[i].in();
	std::sort(seq.begin(), seq.end());
	for(int i = 0; i < T; i++) seq[i].out();
	/********** End **********/
	
	return 0;
}

