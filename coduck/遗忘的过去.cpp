#include <iostream>
#include <algorithm>
#include<math.h>

#include<vector>
#include<queue>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

class node{
    public:
    ll value,s;
    bool operator<(node&n){
        return this->s > n.s;
    }
};


priority_queue<ll> q;

int main() {
    ll n,m;
    cin>>n;
    vector<node>v(n);
    ll a,b;
    for(int i=0;i<n;i++){
        cin>>v[i].s;
    }
    for(int i=0;i<n;i++){
        cin>>v[i].value;
    }
    //cout<<"Kk"<<endl;
    sort(v.begin(),v.end());
    //cout<<"Ll"<<endl;
    int j=0;
    ll num=0;
    for(int i=v[0].s;i>0;i--){
        //cout<<i<<" ";
        while(j<n&&i==v[j].s){
            q.push(v[j].value);
            j++;
            if(j==n)break;
        }
        if(q.empty())continue;
        num+=q.top();
        q.pop();
    }
    cout<<num<<endl;
    return 0;
}