// Problem: A. Walking Master
// Contest: Codeforces - Codeforces Round 858 (Div. 2)
// URL: https://codeforces.com/contest/1806/problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// clang-format off
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); }
void solve(const std::size_t testcase);

int main() {
  std::size_t t = 1;
  read(t);
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  for(int i = 1; i <= t; i++) solve(t);
  return 0;
}
// clang-format on

void solve(const std::size_t testcase){
  int a,b,c,d;
  read(a,b,c,d);
  if(d > b){
    std::cout << -1 << "\n";
    return;
  }
  int ans = 0;
  if(b > d){
    ans += b - d;
    c += b + d;
  }
  
}