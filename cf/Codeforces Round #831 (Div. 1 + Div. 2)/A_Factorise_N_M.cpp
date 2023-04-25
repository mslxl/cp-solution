#include<bits/stdc++.h>

using ll = long long;
using ul = unsigned long long;

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
int main(){
#ifdef ONLINE_JUDGE
	std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  int t;
  read(t);
  while(t--){
    int b;
    read(b);
    std::cout << b << "\n";
  }

	return 0;
}