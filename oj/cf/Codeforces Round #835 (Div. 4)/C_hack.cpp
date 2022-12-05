#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    vector<ll>p;
    while(t--)
    {
        int n;
        cin>>n;
        int x=0, y=0;
        vector<int>a(n);
        for(auto &i:a)
        {
            cin>>i;
            if(i>x) y=x, x=i;
            else if(i>y) y=i;
        }
        for(auto &i:a)
        {
            if(i==x) cout<<x-y<<" ";
            else cout<<i-x<<" ";
        }
        cout<<endl;
    }
}