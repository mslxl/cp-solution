#include<bits/stdc++.h>
#include <numeric>

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


void solve(const std::size_t testcase){
  ll n,c,d;
  read(n,c,d);
  std::vector<ll> s(n);
  for(int i = 0; i < n; i++) read(s[i]);
  std::sort(s.begin(), s.end(), std::greater<ll>());

  if(d * s[0] < c){
    std::cout << "Impossible\n";
    return;
  }

  std::size_t rk = d + 2;
  std::size_t lk = 0;
  while(lk < rk){
    std::size_t mk= lk + (rk - lk + 1) / 2;
    ll sum = 0;
    for(int i = 0 ; i < d; i++){
      if(i % mk < n) sum += s[i % mk];
    }
    if(sum >= c) lk = mk;
    else rk = mk - 1;
  }

  if(lk == d+2){
    std::cout << "Infinity\n";
    return;
  }
  std::cout << lk - 1 << "\n";
}

int main(){

	int t;
  std::cin >> t;
  for(std::size_t i = 1; i <= t; i++){
  	solve(t);
  }

	return 0;
}