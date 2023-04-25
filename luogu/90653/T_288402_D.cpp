#include<bits/stdc++.h>
#include <limits>

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
int main(){
  #define int ll
  int n,m;
  read(n,m);

  if(m >= n) {
    std::cout << 0;
    return 0;
  }
  std::vector<int> seq(n);
  for(int i = 0 ; i< n; i++) read(seq[i]);

  std::sort(seq.begin(), seq.end());
  // if(m == 0){
  //   std::cout << seq[n-1] - seq[0];
  //   return 0;
  // }
  int len = n - m-1;
  int max = std::numeric_limits<int>::max();
  for(int i = 0; i + len < n; i++){
    max = std::min(max, seq[i+len] - seq[i]);
  }
  std::cout << max;

  return 0;
}