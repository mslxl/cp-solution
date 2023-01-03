#include<bits/stdc++.h>
#include <limits>

using ll = unsigned long long;
std::vector<ll> seq;

const int maxn = 2e5 + 17;
int dp[maxn];
int next[maxn];
int maxv = 1;
ll mini = std::numeric_limits<ll>::max();

int main(){
  int n;
  std::cin >> n;
  seq.resize(n);
  for(int i = 0; i < n; i++) {
    std::cin >> seq[i];
    mini = std::min(seq[i], mini);
  }
  std::fill(dp, dp + n, 1);
  std::fill(next, next + n, -1);
  
  for(int i = n-2; i>=0; i--){
    for(int j = i+1; j < n; j++){
      if(seq[j] - seq[i] == 1){
        if(dp[j] + 1 > dp[i]){
          dp[i] = dp[j] + 1;
          next[i] = j;
          if(maxv == dp[i]){
            mini = std::min(mini, seq[i]);
          }else if(maxv < dp[i]){
            mini = seq[i];
            maxv = std::max(maxv, dp[i]);
          }
        }
      }
    }
  }
  std::vector<int> ans;
  for(int i = 0; i < n; i++){
    if(dp[i] == maxv && seq[i] == mini){
      ans.push_back(seq[i]);
      i = next[i];
      while(i != -1 ){
        ans.push_back(seq[i]);
        i = next[i];
      }
      break;
    }
  }
  
  std::cout << ans.size() << std::endl;
  for(auto v:ans){
    std::cout << v << " ";
  }
  return 0;
}