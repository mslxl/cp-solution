#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;

ll a[MAXN];
map<ll,ll> freq;

void tc(){
    ll n;
    cin>>n;
    ll maxfr=0,current_sum=0,ans=0;
    bool found_wildcard=0;
    freq.clear();
    for(ll i=0;i<n;i++){
      cin>>a[i];

      if(a[i]==0){
        if(found_wildcard) ans+=maxfr;
        else ans+=freq[0];

        found_wildcard=1;
        maxfr=0,freq.clear();
      }

      current_sum+=a[i];
      maxfr=max(maxfr,++freq[current_sum]);
    }
    if(found_wildcard) ans+=maxfr;
    else ans+=freq[0];

    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    ll t; cin>>t; while(t--)
        tc();
    return 0;
}