#include<stdio.h>
#include<math.h>
typedef long long ll;


inline int len(ll i){
    int l = 0;
    while(i != 0){
        i/=10;
        l++;
    }
    return l;
}

void solve(){
    ll i;
    scanf("%lld", &i);
    if(i == 0){
        printf("%d\n", 0);
        return;
    }
    ll round = pow(10,len(i)-1);
    printf("%lld\n", i - round);
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        solve();
    }
    return 0;
}