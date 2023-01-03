#include<bits/stdc++.h>
// 自分の得意な言語で
// Let's チャレンジ！！

using ll = long long;
using ul = unsigned long long;
using ld = long double;

template <typename T>
inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){
  char c;T f=1;
  while(!isdigit(c=getchar())) if(c=='-')f=-1;
  x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15);
  x*=f;
}

template <typename T, typename... A> void read(T &value, A &..._t) {
  read(value);
  read(_t...);
}

#define rep(NAME, MAX) for(decltype(MAX) NAME = 0; NAME < MAX; i++)
#define rep1(NAME, MAX) for(decltype(MAX) NAME = 1; NAME <= MAX; i++)
#define repv0(NAME, START) for(decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for(decltype(START) NAME = START; NAME >= 1; NAME--)

// main function
void solve(const std::size_t testcase){
  //coding here
  ll a,b;
  std::cin >> a >> b;
  ll sig = b / std::abs(b);
  std::cout << std::abs(a) * sig;
}

#ifdef int
#undef int
#endif
int main(){
  std::size_t t = 1;
  // std::cin >> t;
  for(std::size_t i = 1; i <= t; i++){
    solve(t);
  }

  return 0;
}
