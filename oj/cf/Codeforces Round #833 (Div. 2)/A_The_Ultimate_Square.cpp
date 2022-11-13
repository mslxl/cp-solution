#include<bits/stdc++.h>
#include <cmath>

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
void solve(){
  ll n;
  read(n);
  if(n == 1 || n == 2){
    std::cout << 1;
  }else if(n == 3 || n == 4) {
    std::cout << 2;
  }else if(n == 5 || n == 6){ 
    std::cout << 3;
  }else {
    std::cout << ll(std::ceil(ld(n) / 2));
  }

   std::cout << std::endl;
}

int main(){
#ifdef ONLINE_JUDGE
	std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif

  int t;
  read(t);
  while(t--){
    solve();
  }
	return 0;
}