#include <bits/stdc++.h>
#ifdef Local
#define tout \
  if (1)     \
  std::cerr
#else
#define tout \
  if (0)     \
  std::cerr
#endif
using ll = long long;
#define rep(i, s, e) for (int i = s; i < e; i++)

const int maxn = 2 * 1e7 + 17;
int cnt[maxn], seq[maxn];

void solve() {
  int n;

  std::cin >> n;
  std::fill_n(cnt, n + 1, 0);
  for (int i = 1; i <= n; i++) {
    std::cin >> seq[i];
  }
  int last_min = INT32_MAX, last_min2 = INT32_MAX;
  for (int i = 1; i <= n; i++) {
    if (seq[i] <= last_min) {
      last_min2 = last_min;
      last_min = seq[i];
    } else if (seq[i] >= last_min && seq[i] < last_min2) {
      cnt[seq[i]]++;
      cnt[last_min]++;
      last_min2 = seq[i];
    } else if (seq[i] >= last_min2) {
      cnt[seq[i]]++;
    }
  }
  int minn = INT32_MAX, idx = -1;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] < minn) {
      minn = cnt[i];
      idx = i;
    }
  }
  assert(idx != -1);
  std::cout << idx << std::endl;
}

int main() {
#ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}