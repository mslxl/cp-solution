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

void solve(const std::size_t testcase) {
  int m, s;
  read(m, s);
  std::set<int> occupy;
  int max = 0;
  for (int i = 0; i < m; i++) {
    int x;
    read(x);
    occupy.insert(x);
    max = std::max(max, x);
  }
  int sum = 0;
  for(int i = 1; ; i++){
    if(occupy.count(i)){
      continue;
    }
    sum += i;
    if(sum > s){
      std::cout << "NO\n";
      return;
    }else if(sum == s){
      for(int j = i + 1; j <= max; j++){
        if(!occupy.count(j)){
          std::cout << "NO\n";
          return;
        }
      }
      std::cout << "YES\n";
      return;
    } 
  }

}

int main() {

  int t;
  std::cin >> t;
  for (std::size_t i = 1; i <= t; i++) {
    solve(t);
  }

  return 0;
}