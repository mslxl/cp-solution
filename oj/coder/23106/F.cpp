
#include <algorithm>
#include <cctype>
#include <cstdio>

template <typename T> T rd() {
  T num = 0;
  bool flag = false;
  char c;
  while ((c = getchar()) && c != '-' && !std::isdigit(c)) {
  }

  if (c == '-') {
    flag = true;
  } else {
    num += c - '0';
  }

  while ((c = getchar()) && std::isdigit(c)) {
    num *= 10;
    num += c - '0';
  }
  // printf("read num %d\n", flag ? -num : num);

  return flag ? -num : num;
}

void solve() {
  int n = rd<int>(), m = rd<int>();
  int cnt[2] = {0};
  for (int i = 0; i < n; i++) {
    int v = rd<int>();
    cnt[v >= m]++;
  }
  int ans = cnt[1] - cnt[0];
  if(ans <= 0){
      ans = -1;
  }
  printf("%d\n", ans);
}

int main() {
  int T;
  T = rd<int>();
  while (T--) {
    solve();
  }

  return 0;
}
