//小z的数列
#include<bits/stdc++.h>
const int maxn = 2 * 1e5;


using ll = unsigned long long;
std::vector<int> seq;
ll dp[maxn];
int main(){
  int n = 0;
  std::cin >> n;
  std::memset(dp, 0, sizeof(dp));
  seq.resize(n);
  for(int i = 0; i < n; i++){
    std::cin >> seq[i];
  }

  dp[0] = seq[0];
  for(int i = 1; i < seq.size(); i++){
    dp[i]= std::max(dp[i-1] + seq[i], dp[i-1] ^ seq[i]);
  }
  std::cout << dp[n-1];
  return 0;

}