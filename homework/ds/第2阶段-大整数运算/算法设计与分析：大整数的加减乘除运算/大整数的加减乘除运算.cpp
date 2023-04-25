//
//  main.cpp
//  step1
//
//  Created by ljpc on 2018/12/4.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
using namespace std;

// 最大长度N，分块长度K
const int N = 10001;
const int K = 10000;
const int T = (int)log10(K); // K=10000, T=4

void char_to_int(const char *s, int *c)
{
	// *s = 1234567890
	// *c = 0000 .... 0012 3456 7890 (K=10000, T=4, c[0] c[1] .... c[N-2] c[N-1])
	// i  = 0         N-3  N-2  N-1  (c的下标索引i)
	int L = (int)strlen(s);
	for (int i=N-1; i>=0; i--) {
		c[i] = 0;
		if (L>=0) {
			for (int j=0; j<T; j++) {
				if (L-T+j < 0) {
					continue;
				}
				c[i] = c[i] * 10 + s[L-T+j] - '0';
			}
			L -= T;
		}
	}
}

void output(int *c)
{
	// *c = 0000 .... 0012 3456 7890 (K=10000, T=4, c[0] c[1] .... c[N-2] c[N-1])
	// i  = 0         N-3  N-2  N-1  (c的下标索引i)
	// out= 1234567890
	bool flag = true;
	for (int i=0; i<N; i++) {
		if (flag && c[i]==0) {
			continue;
		}
		if (flag) { // 第一个非0数字：大数的头块
			printf("%d", c[i]);
			flag = false;
		}
		else { // 大数头块之后的 T 数字块
			int TK = K/10;
			int tmp = c[i];
			while (TK) {
				printf("%d", tmp/TK);
				tmp %= TK;
				TK /= 10;
			}
		}
	}
	printf("\n");
}

void add(int *a, int *b, int *c)
{
	int carry = 0;
	for (int i=N-1; i>=0; i--) {
		c[i] = 0;
		c[i] = a[i] + b[i] + carry;
		carry = c[i] / K;
		c[i] = c[i] % K;
	}
	
}

void sub(int *a, int *b, int *c)
{
	int borrow = 0;
	for (int i=N-1; i>=0; i--) {
		c[i] = 0;
		c[i] = a[i] - b[i] - borrow;
		if (c[i] >= 0) {
			borrow = 0;
		}
		else {
			c[i] = c[i] + K;
			borrow = 1;
		}
	}
	
}

void mul1(int *a, int b, int *c)
{
	long long tmp = 0;
	int carry = 0;
	for (int i=N-1; i>=0; i--) {
		tmp = (long long)a[i] * (long long)b + (long long)carry;
		c[i] = (int)(tmp % K);
		carry = (int)(tmp / K);
	}
	
}

void mul2(int *a, int *b, int *c)
{
	long long tmp = 0;
	int carry = 0;
	for (int i=N-1; i>=0; i--) {
		c[i] = 0;
	}
	for (int i=N-1; i>=0; i--) { // b[i]
		carry = 0;
		for (int j=N-1, idc=i; j>=0&&idc>=0; j--, idc--) { // a[j]
			tmp = (long long)a[j] * (long long)b[i] + (long long)carry + (long long)c[idc];
			c[idc] = (int)(tmp % K);
			carry = (int)(tmp / K);
		}
	}
	
}

int div(int *a, int b, int *c)
{
	long long tmp = 0;
	int remain = 0;
	for (int i=0; i<N; i++) {
		tmp = (long long)a[i] + (long long)remain * (long long)K;
		c[i] = (int)(tmp / b);
		remain = (int)(tmp % b);
	}
	return remain;
	
}

string int2string(int *c)
{
	// *c = 0000 .... 0012 3456 7890 (K=10000, T=4, c[0] c[1] .... c[N-2] c[N-1])
	// i  = 0         N-3  N-2  N-1  (c的下标索引i)
	// out= 1234567890
	stringstream ss;
	bool flag = true;
	for (int i=0; i<N; i++) {
		if (flag && c[i]==0) {
			continue;
		}
		if (flag) { // 第一个非0数字：大数的头块
			ss << c[i];
			//printf("%d", c[i]);
			flag = false;
		}
		else { // 大数头块之后的 T 数字块
			int TK = K/10;
			int tmp = c[i];
			while (TK) {
				ss << tmp / TK;
				//printf("%d", tmp/TK);
				tmp %= TK;
				TK /= 10;
			}
		}
	}
	
	//printf("\n");
	return ss.str();
}


int num1[N];
int num2[N];

int calc(int n)
{
	// 请在这里补充代码，完成本关任务
	/********* Begin *********/
	//你都给我了，我不调库有点说不过去
	std::string s = to_string(n);
	char_to_int(s.c_str(), num1);
	for(int i = n-1; i > 0 ;i--){
		mul1(num1, i, num2);
		std::memcpy(num1, num2, sizeof(num2));
	}
	s = int2string(num1);
	unsigned long long cnt = 0;
	//std::cout << "num:" << s << std::endl;
	for(const auto& ch:s){
		if(ch == '0') cnt++;
	}
	return cnt;
	/********* End *********/
}

int main(int argc, const char * argv[]) {
	
	int n;
	
	scanf("%d", &n);
	
	int tot = calc(n);
	printf("%d\n", tot);
	
	return 0;
}


