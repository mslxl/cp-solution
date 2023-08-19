#include<bits/stdc++.h>
using namespace std;

#define ll long long
const long double eps = 1e-8;
ll n,m;

class node{
    public:
    int a,b;
    bool operator<(node& n){
        return this->a*n.b>this->b*n.a;
    }
};

node N[1000000];

ll f[10000];

int main(){
    ll t;
    cin>>n;
    m=(ll)(log2(n)+eps);
    ll num=0;
    //cout<<m<<endl;
    for(ll i=m;i>1;i--){
        f[i]=(ll)(pow((long double)n,(long double)1/i)+eps);
        //cout<<f[i]<<endl;
        for(int j=i+i;j<=m;j+=i){
            f[i]-=(f[j]-1);
        }
        num+=f[i]-1;
    }
    cout<<num+1<<endl;

    return 0;   
} 

