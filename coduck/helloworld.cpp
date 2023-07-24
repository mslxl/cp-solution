#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<stdlib.h>
#include<queue>
#include<climits>
#include<set>
#include<unordered_map>
#include<tuple>

using ll = long long;

template<typename T>
T read(){
    T x=0,f=1; char ch=getchar();
    while(ch>'9'||ch<'0'){ if(ch=='-'){ f=-1; } ch=getchar(); }
    while(ch>='0'&&ch<='9'){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
    return x*f; 
}
#define read() read<int>()

int main(){
    std:: cout<<"Hello world!";
    return 0;
}