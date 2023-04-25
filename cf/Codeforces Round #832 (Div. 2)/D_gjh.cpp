#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>

using namespace std;

int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch<='9'&&ch>='0'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

const int maxn = 2e5+11;

int binary[maxn][35];
int a[maxn];
int arr[maxn][35];

void to_binary(int n,int x){
    int sum=x;
    int bit=0;
    int num=0;
    while(sum){
        bit=sum%2;
        sum/=2;
        if(bit) binary[n][++num]+=1;
        else binary[n][++num]=0;
    }
}
int judge(int l,int r){
    int flag=0;
    for(int i=1;i<=32;i++){
        int sum=arr[r][i]-arr[l-1][i];
        if(sum!=0){
            flag=1;
        }
        if(sum%2){
            return 0;
        }
    }
    if(flag==0){
        return 2;
    }
    return 1;
}

int main(){
    int n=read(),q=read();
    for(int i=1;i<=n;i++){
        a[i]=read(); to_binary(i,a[i]);
    }
    for(int i=1;i<=32;i++){
        for(int j=1;j<=n;j++){
            arr[j][i]+=arr[j-1][i]+binary[j][i];
        }
    }
    for(int i=1;i<=q;i++){
        int l=read(),r=read();
        int state=judge(l,r);
        if(state==2){
            cout<<"0\n";
            continue;
        }
        if(r-l==1){
            cout<<"-1\n";
            continue;
        }
        if(l==r){
            cout<<"0\n";
            continue;
        } 
        if(state==1){
            if((r-l+1)%2){
                cout<<"1\n";
            }else{
                cout<<"2\n";
            }
        }
        if(state==0){
            cout<<"-1\n";
        }
    }
    return 0;
}
