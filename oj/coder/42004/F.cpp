//帝国时代
#include<bits/stdc++.h>
const int modd = 998244353;

int n;
const int maxn = 2e3 + 17;
using ul = unsigned long long;
std::vector<ul> seq;

ul dp[maxn][maxn];

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  //---
  std::cin >> n;
  seq.resize(n);
  for(int i = 0; i < n; i++){
    std::cin >> seq[i];
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      dp[i][j] = 1;
    }
  }

  for(int i = n; i >= 0; i--){
    for(int j = i + 1; j <n; j++){
      for(int k = j + 1; k < n; k++){
        if(seq[j]-seq[i] == seq[k] - seq[j]){
          dp[i][j] += dp[j][k];
          dp[i][j] %= modd;
        }
      }
    }
  }
  ul ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      ans += dp[i][j];
      ans %= modd;
    }
  }
  std::cout << ans;
  
  return 0;
}