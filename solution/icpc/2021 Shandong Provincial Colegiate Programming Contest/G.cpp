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
 
int n,k;
int divide(int div){
    if(div%n==0){
        std:: cout<<div/n;
        return -1;
    }
    std:: cout<<div/n;
    return div%n;
}
 
int main(){
    n=read(); k=read();
    int sum=0;
    for(int i=1;i<=n;i++){
        int x=read();
        sum+=x;
    }
    std:: cout<<int(sum/n);
    if(k==0){
        return 0;
    }
    std:: cout<<".";
    int temp=sum%n;
    for(int i=1;i<=k;i++){
        temp=(temp<<3)+(temp<<1);
        temp=divide(temp);
        if(temp==-1){
            for(int j=i+1;j<=k;j++){
                std:: cout<<"0";
            }
            return 0;
        }
    }
    return 0;
}
