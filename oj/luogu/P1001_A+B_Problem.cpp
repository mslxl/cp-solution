// Problem: P1001 A+B Problem
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1001
// Memory Limit: 128 MB
// Time Limit: 1000 ms
//

#include <bits/stdc++.h>
#ifdef Local
#define tout                                                                   \
  if (1)                                                                       \
  std::cerr
#else
#define tout                                                                   \
  if (0)                                                                       \
  std::cerr
#endif
#define rep(i, s, e) for (int i = s; i < e; i++)
#define fors(i, s, e) rep(i, s, e + 1)

using ll = long long;
using ul = unsigned long long;

int main() {
#ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  int a, b;
  std::cin >> a >> b;
  std::cout << (a + b);
  return 0;
}
