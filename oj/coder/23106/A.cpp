#include <array>
#include <iostream>

int num_root(int num) { return num % 9; }

const int maxn = 10e5 + 5;
const int modd = 998244353;
int n;

int dp[maxn][10] = {0};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n;

  int num[n];

  for (int i = 0; i < n; i++) {
    std::cin >> num[i];
  }
  // dp[0][0] = 1;

  for (int i = 1; i <= n; i++) {

    dp[i][num[i - 1] % 9] = (dp[i][num[i - 1] % 9] + 1) % modd;

    for (int j = 0; j < 9; j++) {

      dp[i][j] = (dp[i][j] + dp[i - 1][j]) % modd; // Not select current number

      dp[i][((j + num[i - 1]) % 9)] =
          (dp[i][(j + num[i - 1]) % 9] + dp[i - 1][j]) %
          modd; // Select current number
    }
  }
  for (int i = 1; i < 9; i++)
    std::cout << dp[n][i] << ' ';
  std::cout << dp[n][0];

  return 0;
}
