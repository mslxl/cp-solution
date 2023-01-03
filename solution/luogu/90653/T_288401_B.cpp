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
const int maxn = 2e5 + 17;
int a[maxn], b[maxn], result[maxn];

int main(){
  int n,m;
  read(n,m);

  for(int i = n-1; i >=0; i--) read(a[i]);
  for(int i = m - 1; i >= 0; i--) read(b[i]);

  for(int i = 0; i < std::max(n,m); i++){
    const int limit = i + 2;
    if(i >= n){
      result[i] += b[i];
    }else if(i >= m){
      result[i] += a[i];
    }else{
      result[i] += a[i] + b[i];
    }
    
    if(result[i] >= limit){
      result[i+1] = result[i] / limit;
      result[i] %= limit;
    }
  }

  bool skip = true;
  for(int i = std::max(n,m); i>=0; i-- ){
    if(skip && result[i] == 0){
      continue;
    }else{
      skip = false;
    }
    std::cout << result[i] << " ";
  }
  if(skip){
    std::cout << 0;
  }

	return 0;
}