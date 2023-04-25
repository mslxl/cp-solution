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

bool isPrime(int v){
  if(v <= 1) return false;
  for(int i = 2; i * i <= v; i++){
    if(v % i == 0){
      return false;
    }
  }
  return true;
}

void solve(const std::size_t testcase){
  #define int ll
  int n;
  read(n);
  std::vector<int> seq(n);
  for(int i = 0; i < n; i++){
    read(seq[i]);
  }
  std::sort(seq.begin(), seq.end());
  std::set<int> values;
  for(auto i: seq){
    for(int j = 2; j * j <= i; j++){
      if(i % j == 0){
        if(values.count(j) || values.count(i/j)){
          std::cout << "YES\n";
          return;
        }
        values.insert(j);
        values.insert(i/j);
      }
    }
    values.insert(i);
  }
  std::cout << "NO\n";
  #undef int
}

int main(){

	int t;
  std::cin >> t;
  for(std::size_t i = 1; i <= t; i++){
  	solve(t);
  }

	return 0;
}