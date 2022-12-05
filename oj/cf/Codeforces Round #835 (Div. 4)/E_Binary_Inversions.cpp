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
#define int ll
int work(std::vector<int> & seq){
  int cnt = 0;
  int cntOne = 0;
  for(auto i: seq){
    if(i == 1){
      cntOne++;
    }else if(i == 0){
      cnt+=cntOne;
    }
  }
  return cnt;
}

void solve(const std::size_t testcase){
  int n;
  read(n);
  std::vector<int> seq(n);
  int last_one_idx = -1;
  int first_zero_idx = -1;
  for(int i = 0; i < n; i++){
    read(seq[i]);
    if(seq[i] == 0 && first_zero_idx == -1){
      first_zero_idx = i;
    }else if(seq[i] == 1){
      last_one_idx = i;
    }
  }
  int cnt = work(seq);
  if(last_one_idx != -1){
    seq[last_one_idx]= 0;
    cnt = std::max(cnt, work(seq));
    seq[last_one_idx] = 1;
  }
  if(first_zero_idx != -1){
    seq[first_zero_idx] = 1;
    cnt=std::max(cnt, work(seq));
    seq[first_zero_idx] = 0;
  }
  std::cout << cnt << '\n';
}
#undef int
int main(){

	int t;
  std::cin >> t;
  for(std::size_t i = 1; i <= t; i++){
  	solve(t);
  }

	return 0;
}
