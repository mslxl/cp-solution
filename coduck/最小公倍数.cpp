#include<bits/stdc++.h>
#include <numeric>

int main(){
  #define int long long
  int a, b;
  std::cin >> a >> b;

  int p = std::__gcd(a,b);
  std::cout << a / p * b;
}