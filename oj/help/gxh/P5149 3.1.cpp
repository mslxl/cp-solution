#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<aliases.h>
#include<cstdlib>
using namespace std;
struct data{
    int son[29];
    int flag;
}t[1000001];
int num=0,n,a[1000001];
int c[1000001];
long long ans=0;
void build(char *s,int order){
    int len=strlen(s); int begin=0;
    for(int i=0;i<len;i++){
        cout<<begin;int x=s[i]-'a'; 
        if(!t[begin].son[x]) t[begin].son[x]=++num;
        begin=t[begin].son[x];
    }
    t[begin].flag=order;
}
int ask(char *s){
    int len=strlen(s); int begin=0;
    for(int i=0;i<len;i++){
        int x=s[i]-'a'; begin=t[begin].son[x];
    }
    return t[begin].flag;
}
int lowbit(int x){
    return x&(-x);
}
void update(int x,int y){
    for( ;x<=n;x+=lowbit(x)) c[x]+=y;
}
int sum(int x){
    int result=0;
    for( ;x;x-=lowbit(x)) result+=c[x];
    return result; 
}
int main()
{
    scanf("%d",&n); char s1[10],s2[10];
    for(int i=1;i<=n;i++){
        cin>>s1; build(s1,i);
    }
    for(int i=1;i<=n;i++){
        cin>>s2; a[i]=ask(s2);
    }
    for(int i=1;i<=n;i++){
        update(a[i],1); ans+=i-sum(a[i]);
    }
    printf("%lld",ans);
    return 0;
} 
