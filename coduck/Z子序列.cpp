#include<iostream>
using namespace std;
#define ll long long

ll e[1000006];

int main(){
    ll mod=1e9+7;
    ll E=2;
    for(int i=1;i<=1e6;i++){
        e[i]=((E-1)%mod+mod)%mod;
        E*=2;
        E%=mod;
    }
    
}