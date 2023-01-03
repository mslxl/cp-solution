#include<bits/stdc++.h>
const int maxn = 1000 + 17;
int f[maxn][maxn];
int main(){
    int N,V;
    std::cin >> N >> V;
    std::vector<int> v(N+1), w(N+1);
    for(int i = 1; i <= N; i++) std::cin >> v[i] >> w[i];
    
    std::memset(f, 0, sizeof(f));
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= V; j++){
            if(j >= v[i]){
                f[i][j] = std::max(
                    f[i-1][j],
                    f[i-1][j-v[i]]+w[i]
                );
            }else{
                f[i][j] = f[i-1][j];
            }
        }
    }
    std::cout << f[N][V];
    return 0;
}    