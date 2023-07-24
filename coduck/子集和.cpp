#include<bits/stdc++.h>

const int maxn = 20 + 17;
int n, t;
int a[maxn];

int dp[maxn][2];
const int mask = 0b1;


int main(){
  std::cin >> n >> t;

  for(int i = 1; i <= n; i++){
    std::cin >> a[i];
  }

  for(int i = 1; i <= n; i++){
     dp[i][0] = true;
  }



  return 0;
}