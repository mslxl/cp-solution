#include<bits/stdc++.h>
#ifdef Lo
#define test if(1)
#else
#define test if(0)
#endif

typedef long long ll;

const int maxn = 10 + 13;
const int maxk = 1e6;
const int modd = 1e9 + 7;

int n,k;
int dp[maxn][maxk] = {0};

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> k ; 

  for(int i = 1; i <= k; i++){
    dp[1][i] = 1;
  }

  for(int len = 2 ; len<=n; len++ ) {
    int kind_before = 0 ; 
    for(int j = 1 ; j<=k ; j++ ) {
      kind_before +=dp[len-1][j] ; 
      kind_before %=modd; 
    }
    for(int j = 1 ; j<=k ; j++ ) {
      int kind_illeagal = 0 ; 
      for(int x = 2*j ; x <=k ; x+=j) {
          kind_illeagal +=dp[len - 1][x] ; 
          kind_illeagal %=modd; 
      }
      dp[len][j] = (kind_before - kind_illeagal + modd) %modd; 
    }
  }

  ll ans = std::accumulate(dp[n] + 1, dp[n] + k + 1, 0L, [](int l, int r){
      test  std::cout << "+" << r << std::endl;
      return (l + r) % modd;
  });

  std::cout<<ans;
  return 0 ; 
}
