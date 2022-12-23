#include <bits/stdc++.h>
#define rep(NAME, MAX) for (int NAME = 0; NAME < MAX; i++)
#define rep1(NAME, MAX) for (int NAME = 1; NAME <= MAX; i++)
#define repv0(NAME, START) for (int NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for (int NAME = START; NAME >= 1; NAME--)

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

using ll = long long;
using ul = unsigned long long;
using ld = long double;

void solve() {
  ul a, b, c;
  read(a, b, c);

  ul ranran = 1;
  ul time = 0;
  while (std::ceil(1.0 * c / ranran) * b >
         a + std::ceil(1.0 * c / (ranran * 2)) * b) {
    ranran *= 2;
    time += a;
  }
  time += std::ceil(1.0 * c/ranran) * b ;

  std::cout << time << "\n";
}

int main() {
  int t;
  read(t);
  rep(i, t) solve();
  return 0;
}