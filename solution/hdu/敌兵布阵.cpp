#include<bits/stdc++.h>
#define lowbit(x) ((-x) & x)
using namespace std;
using ll = unsigned long long;
const int array_size = 50000 + 14;
array<ll, array_size> bit;
int N;
void update(int i, int v){
    for(;i<=array_size; i+=lowbit(i))
        bit[i]+=v;
}
ll prefix_sum(int i){
    ll s = 0;
    for(;i > 0; i -= lowbit(i))
        s += bit[i];
    return s;
}

void solve(){
    cin >> N;
    bit.fill(0);
    for(int i = 1; i <= N; i++){
        int v;
        std::cin >> v;
        update(i,v);
    }
    string wd;
    while(cin >> wd){
        if(wd == "End") break;
        int x,y;
        cin >> x >> y;
        if(wd == "Add") {
            update(x, y);
        }else if(wd == "Sub"){
            update(x, -y);
        }else{
            std::cout << (prefix_sum(y) - prefix_sum(x-1)) << "\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 1; i <= T;i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}