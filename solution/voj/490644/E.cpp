#include<bits/stdc++.h>
#define rep(i,s,e) for(int i = s; i < e; i++)
#define fors(i,s,e) rep(i,s,e+1)

const int maxn = 1e5;
int n;
int seq[maxn];
int sorted[maxn];
void solve(){
    std::cin >> n;
    rep(i,0,n) std::cin >> seq[i];
    std::memcpy(sorted, seq, n * sizeof(int));
    std::sort(sorted, sorted + n);

    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        if(seq[i] != sorted[i + ans])
            ans++; 
    }    
    std::cout << ans << std::endl;

}
int main(){
    #ifndef Local
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    #endif

    int T;
    std::cin >> T;
    while(T--){
        solve();
    }
    return 0;
}