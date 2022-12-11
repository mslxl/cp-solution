#include <bits/stdc++.h>
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
void solve(const std::size_t testcase) {
  #define int ll
  int n;
  read(n);
  int max = std::numeric_limits<int>::min(),
      min = std::numeric_limits<int>::max();
  std::map<int, int> map;
  for (int i = 0; i < n; i++) {
    int num;
    read(num);
    map[num]++;
    min = std::min(min, num);
    max = std::max(max, num);
  }

  if(max == min){
    std::cout << map[max] * (map[min] - 1) << "\n";
  }else{
    std::cout << map[max] * map[min] * 2 << "\n";
  }
  #undef int
}

int main() {

  int t;
  std::cin >> t;
  for (std::size_t i = 1; i <= t; i++) {
    solve(t);
  }

  return 0;
}