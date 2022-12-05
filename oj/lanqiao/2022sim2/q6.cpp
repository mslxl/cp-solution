#include<iostream>
#include<vector>
int main(){
  using ll = long long;
  using ld = long double;
  ld t,c,s;
  std::cin >> t >> c >> s;
  ld speed = c / t;
  ld total = s / speed;
  std::cout << ll(total - t);
  return 0;
}