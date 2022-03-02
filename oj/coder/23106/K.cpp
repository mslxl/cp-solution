#pragma GCC optimize(2)
#include <bits/stdc++.h>

#ifdef Lo
#define test if (1)
#else
#define test if (0)
#endif

const int maxn = 1e5;

const int green = 0b1;
const int red = 0b10;
const int black = 0b100;
const int colors[] = {green, red, black};

int dp[maxn][8][8][8] = {0};

void solve(const std::string &predict) {
  for (auto f : colors) {
    for (auto s : colors) {
      for (auto t : colors) {
        dp[2][t][s][f] = ((f & green) == green) + ((s & green) == green) +
                         ((t & green) == green);

        dp[1][t][s][f] = ((f & green) == green) + ((s & green) == green);
      }
    }
  }

  for (int idx = 2; idx < predict.size(); idx++) {
    const char &c = predict[idx];
    assert(c != 'X');
    if (c == 'G') {
      for (int any_color1 : colors) {
        for (int any_color2 : colors) {
          dp[idx][any_color1][green][green] =
              std::max(dp[idx - 1][any_color2][any_color1][green] + 1,
                       dp[idx][any_color1][green][green]);

          dp[idx][green][any_color1][green] =
              std::max(dp[idx - 1][any_color2][green][any_color1] + 1,
                       dp[idx][green][any_color1][green]);

          dp[idx][green][green][any_color1] = std::max(
              dp[idx - 1][any_color2][green][green] + (any_color1 == green),
              dp[idx][green][green][any_color1] );
        }
      }
    } else if (c == 'R') {
      for (int any_color1 : colors) {
        for (int any_color2 : colors) {
          dp[idx][any_color1][red][red] =
              std::max(dp[idx - 1][any_color2][any_color1][red],
                       dp[idx][any_color1][red][red]);

          dp[idx][red][any_color1][red] =
              std::max(dp[idx - 1][any_color2][red][any_color1],
                       dp[idx][red][any_color1][red]);

          dp[idx][red][red][any_color1] = std::max(
              dp[idx - 1][any_color2][red][red] + (any_color1 == green),
              dp[idx][red][red][any_color1]);
        }
      }
    } else if (c == 'B') {
      for (int any_color : colors) {
        dp[idx][red][black][green] = std::max(
            dp[idx - 1][any_color][red][black] + 1, dp[idx][red][black][green]);
        dp[idx][black][red][green] = std::max(
            dp[idx - 1][any_color][black][red] + 1, dp[idx][black][red][green]);

        dp[idx][red][green][black] = std::max(
            dp[idx - 1][any_color][red][green], dp[idx][red][green][black]);
        dp[idx][green][red][black] = std::max(
            dp[idx - 1][any_color][green][red], dp[idx][green][red][black]);

        dp[idx][black][green][red] = std::max(
            dp[idx - 1][any_color][black][green], dp[idx][black][green][red]);
        dp[idx][green][black][red] = std::max(
            dp[idx - 1][any_color][green][black], dp[idx][green][black][red]);
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::string line;
  std::cin >> n >> line;
  solve(line);

  int ans = 0;

  for (auto f : colors) {
    for (auto s : colors) {
      for (auto t : colors) {
        ans = std::max(dp[line.size() - 1][t][s][f], ans);
      }
    }
  }
  std::cout << ans << std::endl;

  return 0;
}
