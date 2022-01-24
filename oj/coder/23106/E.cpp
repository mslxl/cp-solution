#include <cstdio>
typedef unsigned long long ll;
int main() {
  ll T, n, m;
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld%lld", &n, &m);
    if (m == 1) {
      printf("-1\n");
      continue;
    } else {
      ll ppl = n - 1;
      ll amt = m - 1;
      ll times = ppl / amt;
      if (ppl % amt != 0) {
        times++; // 有余数向上取整
      }
      ll ans = times * 2 - 1;
      printf("%lld\n", ans);
    }
  }
}
