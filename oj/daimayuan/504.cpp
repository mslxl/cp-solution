// 连续子序列
#include<bits/stdc++.h>
#include <unordered_map>
using ll = unsigned long long;
const int maxn = 2e5 + 17;
int n;
ll seq[maxn];
std::map<int,int> dp;

int main(){
  std::cin >> n;
  for(int i = 0; i < n; i++) std::cin >> seq[i];

  int max = 0;

  for(int i = 0; i < n;i++){
    dp[seq[i]] = std::max(dp[seq[i]], dp[seq[i]-1] + 1);
    max = std::max(dp[seq[i]], max);
  }

  for(const auto pair: dp){
    if(pair.second == max){
      std::cout << max << std::endl;
      for(int i = pair.second; i > 0; i--){
        std::cout << pair.first - i + 1<< " ";
      }
      break;
    }
  }
}