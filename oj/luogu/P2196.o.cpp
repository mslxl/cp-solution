// P_2196_NOIP_1996_提高组_挖地雷
#include <bits/stdc++.h>
#define rep(i, s, e) for (int i = s; i < e; i++)
#define int long long
const int maxn = 20 + 17;
int n;

int num_mine[maxn];

bool joint[maxn][maxn];
int parent[maxn];
int dp[maxn];
int max = 0;

#undef int
int main() {
#define int long long
#ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif

  std::memset(dp, 0, sizeof(dp));
  std::memset(joint, false, sizeof(dp));
  std::fill_n(parent, maxn, -1);

  std::cin >> n;
  rep(i, 0, n) {
    std::cin >> num_mine[i];
    dp[i] = num_mine[i];
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      std::cin >> joint[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (joint[i][j]) {
        int n = std::max(dp[i] + num_mine[j], dp[j]);
        if (n > dp[j]) {
          dp[j] = n;
          parent[j] = i;
        }
      }
    }
  }

  std::stack<int> route;
  int p = n - 1;


  for(int i = 0; i < n; i++){
    if(dp[i] > max){
      max = dp[i];
      p = i;
    }
  }

  route.push(p + 1);
  while (parent[p] != -1) {
    route.push(parent[p] + 1);
    p = parent[p];
  }
  std::cout << route.top();
  route.pop();
  while (!route.empty()) {
    std::cout << " " << route.top();
    route.pop();
  }
  std::cout << std::endl << max;
}