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

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];

    }
    ll num=0;
    for(int i=2;i<=n-1;i++){
        if(v[i]>=v[i-1]&&v[i]>=v[i+1]){
            num++;
        }
    }
    cout<<num<<endl;
    return 0;
}

