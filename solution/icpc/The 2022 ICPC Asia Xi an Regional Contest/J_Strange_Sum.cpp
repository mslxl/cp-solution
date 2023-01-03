#include<bits/stdc++.h>
#define rep(NAME, MAX) for(decltype(MAX) NAME = 0; NAME < MAX; i++)
#define rep1(NAME, MAX) for(decltype(MAX) NAME = 1; NAME <= MAX; i++)
#define repv0(NAME, START) for(decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for(decltype(START) NAME = START; NAME >= 1; NAME--)
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

int main(){
  ll n;
  read(n);
  std::vector<ll> seq(n);
  rep(i, n) read(seq[i]);
  std::sort(seq.begin(), seq.end());
  std::cout << std::max(0LL, std::max(seq[n-1], n >= 2? seq[n-1] + seq[n-2]: 0LL));


	return 0;
}