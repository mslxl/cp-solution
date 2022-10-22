// 窗口的星星
#include<bits/stdc++.h>
#ifdef Local
#define tout if(1) std::cerr
#else
#define tout if(0) std::cerr
#endif
using ll = long long;
using ull = unsigned long long;
#define rep(i,s,e) for(int i = s; i < e; i++)
#define fors(i,s,e) rep(i,s,e+1)

template <typename T>
void read(T& value) {
  value = 0;
  char ch = getchar();
  bool flag = false;
  while (!std::isdigit(ch)) {
    if (ch == '-')
      flag = true;
    ch = getchar();
  }
  while (std::isdigit(ch)) {
    ch = getchar();
    value = value * 10 + (ch - '0');
  }
  if (flag)
    value *= -1;
}

template <typename T, typename... A>
inline void read(T& value, A&... _t) {
  read(value);
  read(_t...);
}

int main(){ 
  #ifndef Local
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  #endif


  return 0;
}
