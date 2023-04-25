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
  int l,r,x;
  int start, fin;
  read(l,r,x,start,fin);
  if(start == fin){
    std::cout << "0\n";
    return;
  }
  if(start - x < l && start + x > r){
    std::cout << "-1\n";
    return;
  }

  int max = std::max(start,fin);
  int min = std::min(start, fin);

  if(max-min >= x){
    std::cout << "1\n";
    return;
  }else if(max - min < x && ((min - x) >=l ||(max + x) <= r)){
    std::cout << "2\n";
    return;
  }else{
    if(min + x > max && min + x <= r){
      if(max - x < min && r - l > x && max - l >= x){
        std::cout << "3\n";
        return;
      }
    }

  }
  std::cout << "-1\n";

}

int main(){

	int t;
  std::cin >> t;
  for(std::size_t i = 1; i <= t; i++){
  	solve(t);
  }

	return 0;
}