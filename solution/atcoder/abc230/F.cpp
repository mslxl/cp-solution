// Predilection
#include <bits/stdc++.h>

const int modd = 998244353;
const int maxn = 2e5 + 17;
int N;
std::vector<int> seq;
std::vector<int> prefix;
std::vector<int> dp;

std::map<int, int> map;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> N;
  seq.resize(N+2);
  prefix.resize(N+2);
  dp.resize(N+2);

  for (int i = 1; i <= N; i++) {
    std::cin >> seq[i];
  }
  for(int i = 1; i <= N; i++){
    prefix[i] = prefix[i-1] + seq[i];
  }
  dp[1] = 1;
  for(int i = 1; i <= N; i++){
    dp[i+1] = 2 * dp[i] - dp[map[prefix[i]]];
    dp[i+1] = (dp[i+1] + modd)%modd;
    map[prefix[i]] = i;
  }
  std::cout << dp[N];
  


  return 0;
}