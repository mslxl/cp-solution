#include<iostream>
#include<vector>
#define ll long long
using namespace std; 
int main(){
    ll n;
    cin>>n;
    vector<ll> v(n+1);
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        v[a]++;
        v[b]++;
    }
    ll num=0;
    for(int i=1;i<=n;i++){
        if(v[i]==1){
            num++;
        }
    }
    cout<<num+1<<endl;
	return 0;
}