#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
bool cmp(ll a,ll b){
    return a>b;
}

ll v[1000000];

int main()
{
    double n,k,c,w;
    cin>>n>>k>>c>>w;
    
    vector<ll> xz(n+1);
    vector<ll> sz(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>xz[i]>>sz[i];
    }
    ll num=1;
    vector<double>dp(n+2);
    dp[n+1]=0;
    for(int i=n;i>0;i--){
        if(xz[i]==1){
            dp[i]=max(dp[i+1],dp[i+1]*(1-0.01*k)+sz[i]*w);
        }
        else{
            dp[i]=max(dp[i+1],dp[i+1]*(1+0.01*c)-sz[i]*w);
        }
    }
    cout<<fixed<<setprecision(2)<<dp[1]<<endl;
    return 0;
}

