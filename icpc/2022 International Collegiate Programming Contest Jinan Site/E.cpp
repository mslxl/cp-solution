#include<bits/stdc++.h>

void solve(){
    int n,k;
    std::cin >> n >> k;
    if(k % 2 == 0){
        std::cout << "Yes\n";
        return;
    }
    int even, odd;
//    if(n % 2 == 0){
//        even = odd = n/2;
//    }else{
//        even = n / 2;
//        odd = n - even;
//    }
    even = n / 2;
    odd = n - even;

    int seg_odd = odd - (k+1)/2 * (n/k);
    int seg_even = even - k/2 * (n/k);
    if(seg_odd >= 0 && seg_odd <= (k+1)/2 && seg_even <= k/2 && seg_even >= 0){
        std::cout << "Yes\n";
    }else{
        std::cout << "No\n";
    }

}

int main(){
    int T;
    std::cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
