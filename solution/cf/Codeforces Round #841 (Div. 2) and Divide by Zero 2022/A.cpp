// clang-format off
// 自分の得意な言語で
// Let's チャレンジ！！
#include <bits/stdc++.h> 
#include <functional>
using ll = long long; using ul = unsigned long long; using ld = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); }
void solve(const std::size_t testcase);
#define rep(NAME, MAX) for(decltype(MAX) NAME = 0; NAME < MAX; NAME++)
#define rep1(NAME, MAX) for(decltype(MAX) NAME = 1; NAME <= MAX; NAME++)
#define repv0(NAME, START) for(decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for(decltype(START) NAME = START; NAME >= 1; NAME--)
int main() {
  std::size_t t = 1;
  read(t);
  rep1(i, t) solve(t);
  return 0;
}
// clang-format on

// coding here
#define int ul
void solve(const std::size_t testcase) {
  int n;
  read(n);

  std::vector<int> seq(n);
  rep(i, n) read(seq[i]);

  if (n == 1) {
    std::cout << seq[0] * 2022<< std::endl;
    return;
  }
  std::sort(seq.begin(), seq.end());

  for (int i = 0; i < n - 1; i++) {
    seq[i+1] = seq[i] * seq[i+1];
    seq[i] = 1;
  }


  std::cout << ((n-1) + seq[n-1]) * 2022<< std::endl;

  // std::cout<<"hello,world"<<std::endl;
}
