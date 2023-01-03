#include <bits/stdc++.h>
using ll = long long;
template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type read(T &value) {
  value = 0;
  char ch = getchar();
  bool flag = false;
  while (!std::isdigit(ch)) {
    if (ch == '-')
      flag = true;
    ch = getchar();
  }
  while (std::isdigit(ch)) {
    value = value * 10 + (ch - '0');
    ch = getchar();
  }
  if (flag)
    value *= -1;
}

template <typename T, typename... A> void read(T &value, A &..._t) {
  read(value);
  read(_t...);
}
int main() {
  ll n, m;
  read(n,m);
  std::vector<ll> seq(n);
  for (ll i = 0; i < n; i++) read(seq[i]);
  if (m >= n-1) {
    std::cout << 0;
    return 0;
  }
  std::sort(seq.begin(), seq.end());
  ll ans = seq[n - 1] - seq[0];
  for (ll i = 0; i < n; i++) {
    ll ops = m - 2 * i;
    if (ops > 0 && ops >= i) {
      ans = std::min(ans, seq[n - 1 - ops] - seq[i]);
    }
    ops = m - i;
    if (ops < 0)
      continue;
    ops = ops / 2;
    ops = std::min(i, ops);
    ans = std::min(seq[n - 1 - ops] - seq[i], ans);
  }
  std::cout << ans << "\n";
  return 0;
}