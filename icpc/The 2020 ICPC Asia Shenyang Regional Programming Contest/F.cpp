#include<bits/stdc++.h>
using ll = long long;
int main() {
    ll n;
    std::cin >> n;
    std::vector<ll> seq(n );
    std::vector<ll> ord(n );
    for (int i = 0; i < n; i++) {
        std::cin >> seq[i];
        ord[i]= seq[i];
    }
    std::sort(ord.begin(), ord.end());
    ll pre1=0, pre2=0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        pre1 += seq[i];
        pre2 += ord[i];
        if(pre1 == pre2) ans++;
    }
    std::cout << ans << "\n";
    return 0;
}
