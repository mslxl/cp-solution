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
  ll n;
  read(n);
  std::vector<ll> seq(n);
  for(int i = 0; i < n; i++){
    read(seq[i]);
  }
  std::vector<ll> max(seq.begin(), seq.end());
  std::sort(max.begin(), max.end());
  for(auto l : seq){
    if(l == max[max.size() - 1]){
      std::cout << l - max[max.size() - 2] << ' '; 
    }else{
      std::cout << l - max[max.size() - 1] << ' ';
    }
  }

  std::cout << "\n";
}

int main(){

	int t;
  std::cin >> t;
  for(std::size_t i = 1; i <= t; i++){
  	solve(t);
  }

	return 0;
}