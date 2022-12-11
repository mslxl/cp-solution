#include<bits/stdc++.h>

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
  ll n,m;
  read(n,m);
  std::vector<ll> seq(n+1, 1);
  for(int i = 0; i < m; i++){
    ll fst, snd;
    read(fst, snd);
    if(fst == snd) continue;
    else if(fst > snd) seq[fst] = std::max(seq[fst], snd+1);
    else seq[snd] = std::max(seq[snd], fst + 1);
  }
  ll ans = 0;
  for(ll i = 1; i <= n; i++){
    seq[i] = std::max(seq[i], seq[i-1]);
    ans += (i-seq[i]+1);
  }
  std::cout << ans << "\n";
}

int main(){

	int t;
  std::cin >> t;
  for(std::size_t i = 1; i <= t; i++){
  	solve(t);
  }

	return 0;
}