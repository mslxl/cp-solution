// 九小时九个人九扇门
// tag:背包
#include <bits/stdc++.h>
#include <type_traits>

template <class T>
constexpr typename std::enable_if<std::is_integral<T>::value, T>::type
root(T num) {
  const auto v = num % 9;
  return v == 0 ? 9 : v;
}


const int modd = 998244353;
const int maxn = 1e5 + 17;
std::vector<int> seq;

int dp[maxn][10];

int main() {
  int n;
  std::cin >> n;
  seq.resize(n);
  for (int i = 0; i < n; i++)
    std::cin >> seq[i];

  dp[0][root(seq[0])]++;

  for (int i = 1; i < n; i++) {
    dp[i][root(seq[i])]++;

    for (int j = 1; j <= 9; j++) {
      dp[i][root(j + seq[i])] += dp[i - 1][j]; // select
      dp[i][j] += dp[i - 1][j]; // not select

      dp[i][root(j + seq[i])] %= modd;
      dp[i][j] %= modd;
    }
  }
  for (int i = 1; i <= 9; i++) {
    std::cout << dp[n - 1][i] << " ";
  }

  return 0;
}