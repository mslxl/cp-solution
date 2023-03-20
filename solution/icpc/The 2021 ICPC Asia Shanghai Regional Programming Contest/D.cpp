#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll p,ll q){
    ll t;
    t=p;
    while(t!=0){
        t=p%q;
        p=q;
        q=t;
    }
    return p;
}
int main(){
    int index=1;
    int count=1;
    cin>>count;
    for(int i=0;i<count;i++){
        ll p,q;
        cin>>p>>q;
        ll t1=p*p-4*q*q;
        ll t2=sqrt(t1);
        if(t2*t2==t1)
            index=1;
        else
            index=0;
        ll gcdd=gcd(p+t2,q*2);
        if(index==0)
            printf("0 0\n");
        else{
            cout<<q*2/gcdd<<" "<<(p+t2)/gcdd<<endl;
        }
    }
}
