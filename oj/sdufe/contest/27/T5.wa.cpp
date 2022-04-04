#include<bits/stdc++.h>

#ifdef Local
#define test if(1)
#else
#define test if(0)
#endif


typedef unsigned long long ll;
const int inf = 0x3f3f3f;
const int maxn = 100000 + 15;
const int maxm = 100000 + 15;

int N;
int K;

ll dp[maxn][3];


int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> K;
  if(N == K){
    std::cout << 0;
    return 0;
  }else if(N > K){
    std::cout << (N - K);
    return 0;
  }

  std::memset(dp, inf, sizeof(dp));
  dp[N][0] = 0;
  dp[N][1] = 0;
  dp[N][2] = 0;

  for(int i = 0; i < maxn; i++){
    if(i - 1 >= 0){
      // forward 1
      dp[i][0] = std::min(dp[i-1][0] + 1, dp[i][0]);
      dp[i][0] = std::min(dp[i-1][1] + 1, dp[i][0]);
      dp[i][0] = std::min(dp[i-1][2] + 1, dp[i][0]);
    }

    if(i - 1 >= 0){
      // backward 1
      dp[i-1][1] = std::min(dp[i][0] + 1, dp[i-1][1]);
      dp[i-1][1] = std::min(dp[i][1] + 1, dp[i-1][1]);
      dp[i-1][1] = std::min(dp[i][2] + 1, dp[i-1][1]);


      i--;
      if(i * 2 < maxn){
        // a big step
        dp[i * 2][2] = std::min(dp[i][0] + 1, dp[i * 2][2]);
        dp[i * 2][2] = std::min(dp[i][1] + 1, dp[i * 2][2]);
        dp[i * 2][2] = std::min(dp[i][2] + 1, dp[i * 2][2]);
      }
      i++;
    }

    if(i * 2 < maxn){
      // a big step
      dp[i * 2][2] = std::min(dp[i][0] + 1, dp[i * 2][2]);
      dp[i * 2][2] = std::min(dp[i][1] + 1, dp[i * 2][2]);
      dp[i * 2][2] = std::min(dp[i][2] + 1, dp[i * 2][2]);
    }

  }
  test {
    for(int i = 0; i < 20; i++){
      for(int j = 0; j < 3; j++){
        std::cout <<  "dp("<< i <<", " << j << ") = " << dp[i][j] << std::endl;
      }
    }
  }
  std::cout << std::min(dp[K][0], std::min(dp[K][1], dp[K][2]));

  return 0;
}
