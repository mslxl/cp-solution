#include<iostream>
#define ll long long
#include<bits/stdc++.h>
ll k,a,b;
std::vector<ll> q;
std::vector<ll> v;
void dfs(ll x){
    //std::cout<<x<<std::endl;
    if(std::find(v.begin(),v.end(),x)!=v.end()){
        std::cout<<x<<std::endl;
        return ;
    }
    v.push_back(x);
    if(x==1)return ;
    ll c=0;
    for(int i=0;i<=100;i++){
        c=i;
        //std::cout<<x<<std::endl;
        if(x/q[i]<k+1)break;
    }
    ll a=x-q[c];
    ll b=(a-1)/k+1;
    //std::cout<<a<<" "<<b<<" "<<c<<std::endl;
    dfs(b);
}



void solve(){
   // std::cout<<"kkkkkkk"<<std::endl;
    v.clear();
    q.clear();
    std::cin>>k>>a>>b;
    q.push_back(1);
    for(int i=1;i<=100;i++){
        q.push_back(q[i-1]*(k+1));
        //std::cout<<q[i]<<" ";
        if(a/q[i]<k+1&&b/q[i]<k+1)break;
    }
    dfs(a);
    dfs(b);
}


int main(){
    ll test=1;
    std::cin>>test;
    while(test--){
        solve();
    }

}