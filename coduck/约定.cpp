#include <iostream>
#include <algorithm>
#include<math.h>
using namespace std;
#include<vector>
#define ll long long
#define pll pair<ll,ll>

ll dp[1003][1003];
void solve(){
    ll n,m,k;
    ll mod=2012;
    cin>>n>>k;
    dp[1][0]=1;
    dp[2][0]=1;
    for(int i=2;i<=n;i++){
        dp[i][0]=1;
        for(int j=1;j<=k&&j<=i-1;j++){
            dp[i][j]=dp[i-1][j]*(j+1)+dp[i-1][j-1]*((i-1)-j+1);
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n][k]<<endl;
}

int main()
{
    ll t;
    t=1;
   //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

