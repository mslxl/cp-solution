#include <bits/stdc++.h>
constexpr int maxn = 1e4 + 17;
using task = std::pair<int, int>;
using ll = long long;

std::vector<task> tasks;
int n, k;

int dp[maxn];
int sum[maxn];

int scan_task = 0;

int main() {
  std::cin >> n >> k;
  tasks.resize(k);
  std::memset(dp, 0, sizeof(dp));
  std::memset(sum, 0, sizeof(sum));

  for (int i = 0; i < k; i++) {
    std::cin >> tasks[i].first >> tasks[i].second;
    sum[tasks[i].first]++;
  }
  std::sort(tasks.begin(), tasks.end(), [](const task &lhs, const task &rhs) {
    if (lhs.first == rhs.first) {
      return lhs.second < rhs.second;
    } else {
      return lhs.first > rhs.first;
    }
  });

  for (int i = n; i > 0; i--) {
    if (sum[i] == 0){
      // 当前不处于任务开始点
      // 无内鬼，发点色图
      dp[i] = dp[i + 1] + 1;
    }else{
      // 当前有 sum[i] 个任务
      for(int j = 1; j <= sum[i]; j++){
        // 选第 scan_task 个任务是不是能摸，
        // 能就选
        if(dp[i + tasks[scan_task].second] > dp[i]){
          dp[i] = dp[i + tasks[scan_task].second];
        }
        scan_task++;
      }
    }
  }

  std::cout << dp[1];
  return 0;
}
