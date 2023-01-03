#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
typedef long long ll;
int n;
const int maxn = 10e6 + 100;
ll ans = 0;
ll cnt[1010] = {0};

inline int f(int ai, int aj) { return std::abs(ai + aj - 1000); }

int main() {
  std::memset(cnt, 0, sizeof(cnt));

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    cnt[num]++;
  }

  for (int i = 0; i <= 1001; i++) {
    for (int j = i; j <= 1001; j++) {

      if (cnt[i] == 0)
        break;
      else if (cnt[j] == 0)
        continue;

      if (i == j) {
        ans += (cnt[i] + cnt[i] * (cnt[i] - 1) / 2) * f(i, j); // 组合数！
      } else {
        ans += (cnt[i] * cnt[j]) * f(i, j);
      }

    }
  }

  printf("%lld", ans);

  return 0;
}
