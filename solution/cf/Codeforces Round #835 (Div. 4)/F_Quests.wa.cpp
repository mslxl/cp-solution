#include <bits/stdc++.h>

using ll = long long;
using ul = unsigned long long;
using ld = long double;

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

#define int ll
void solve(const std::size_t testcase) {
  int n, c, d;
  read(n, c, d);
  ll sum = 0;
  std::vector<ll> award(n);
  for (int i = 0; i < n; i++) {
    read(award[i]);
    sum += award[i];
  }
  std::sort(award.begin(), award.end(), std::greater<ll>());
  if (d * award[0] < c) { // k == 1 still not satifty
    std::cout << "Impossible\n";
    return;
  } else if (d * award[0] == c) {
    std::cout << 0 << '\n';
    return;
  } else {
    int v = 0;
    for (int i = 0; i < std::min(d, n); i++) {
      v += award[i];
    }
    if (v >= c) {
      std::cout << "Infinity\n";
      return;
    }
  }
  int trash = n;
  for (int k = d; k > 0; k--) {
    int loop = d / k;
    int remain = d % k;
    int target = 0;
    if (k > n) {
      target = loop * sum;
      int realRemain = remain - (k - n) - 1;
      for (int i = 0; i < realRemain; i++) {
        target += award[i];
      }
    } else {
      int v = 0;
      for (int i = 0; i < k; i++) {
        v += award[i];
      }
      target = loop * v;
      for (int i = 0; i < remain; i++) {
        target += award[i];
      }
    }
    if (target >= c) {
      std::cout << k  << '\n';
      return;
    }
  }
}
#undef int

int main() {

  int t;
  std::cin >> t;
  for (std::size_t i = 1; i <= t; i++) {
    solve(t);
  }

  return 0;
}