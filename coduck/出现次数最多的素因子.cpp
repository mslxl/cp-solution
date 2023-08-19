#include<iostream>
#include<cstdio> 
using namespace std;
#define ll long long
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<math.h>
#include<tuple>
ll qpow(ll a,ll b,ll mod) {
    ll ans=1;
    while(b>0) {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }   
    return ans;
}

ll panpri(ll x){
    for(int i=2;i<=x/i;i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}

ll exgcd(ll a, ll b, ll & x, ll & y) { 
    if (b == 0) return x = 1, y = 0, a; 
    ll r = exgcd(b, a % b, x, y); 
    tie(x, y) = make_tuple(y, x - (a/b)*y); 
    return r; 
}

const int maxn=1e6+13;
bool vis[maxn+5];
int prime[maxn+5],cnt=0,phi[maxn+5],pri[maxn+5];
void get_EulerFunction(){
    for(int i=2;i<=maxn;i++){
        if(!vis[i])prime[++cnt]=i,phi[i]=i,pri[i]=1;
        for(int j=1;j<=cnt&&i*prime[j]<=maxn;j++){
            int x=i*prime[j];
            vis[x]=1;
            if(i%prime[j]==0){
                phi[x]=phi[prime[j]];
                break;
            }
            phi[x]=phi[prime[j]];
        }
    }
}

int main(){
    ll t;
    t=1;
//    cin>>t;
//get_EulerFunction();
    while(t--){
            ll n;
            ll x;
            ll num=0;
            cin>>n;
            ll ans=0;
            for(int i=2;i<=n/i;i++){
                ans=0;
                while(n%i==0){
                    ans++;
                    n/=i;
                }
                if(num<=ans){
                    num=ans;
                    x=i;
                }
            }
            if(num==1){
                if(panpri(n)){
                    x=max(x,n);
                }
            }
            cout<<x<<endl;
    }
    return 0;
}