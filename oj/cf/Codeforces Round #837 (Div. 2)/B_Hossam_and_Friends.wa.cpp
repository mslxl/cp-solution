#include <bits/stdc++.h>
#include <queue>

using ll = long long;
using ul = unsigned long long;
using ld = long double;


template <typename T>
T qpow(T a, ll n){
    T ans = 1; 
    while (n){
        if (n & 1) ans = ans * a; 
        n >>= 1;
        a = a * a;
    }
    return ans;
}

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

void solve(const std::size_t testcase) {
  int n, m;
  read(n, m);
  int counter = 1;

  std::map<int, int> smap;
  std::map<int, int> emap;
  for (int i = 0; i < m; i++) {
    int fst, snd;
    read(fst, snd);
    smap[fst]=counter;
    emap[snd] = counter;
    counter++;
  }

  std::set<int> status;
  int len = 0;
  ll ans = 0;
  for(int i = 1; i <= n; i++){
    if(emap.count(i) && status.count(emap[i])){
      status.clear();
      ans += qpow(2,len) - 1;
      len = 0;
    }
    if(smap.count(i)){
      status.insert(smap[i]);
    }

    len++;
  }
  ans += qpow(2, len)-1;
  std::cout << ans << "\n";
}

int main() {

  int t;
  std::cin >> t;
  for (std::size_t i = 1; i <= t; i++) {
    solve(t);
  }

  return 0;
}