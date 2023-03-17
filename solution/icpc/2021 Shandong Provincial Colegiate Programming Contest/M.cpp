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
 
int read(){
    int x=0,f=1; char ch=getchar();
    while(ch>'9'||ch<'0'){ if(ch=='-'){ f=-1; } ch=getchar(); }
    while(ch>='0'&&ch<='9'){ x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
    return x*f; 
}
 
const int maxn = 511;
 
int a[maxn][maxn];
int b[maxn][maxn];
int c[maxn][maxn];
 
int main(){
    int n=read(),m=read(); 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=b[i][j]=c[i][j]=getchar()^48;
        }
        getchar();
    }
    for(int i=1;i<=n;i+=2){
        for(int j=1;j<m;j++){
            a[i][j]=1;
        }
    }
    for(int i=2;i<=n;i+=2){
        for(int j=2;j<=m;j++){
            b[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        a[i][1]=b[i][m]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std:: cout<<a[i][j];
        }
        std:: cout<<std:: endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std:: cout<<b[i][j];
        }
        std:: cout<<std:: endl;
    }
    return 0;
}
