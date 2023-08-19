#include<bits/stdc++.h>

using ll = long long;

ll lcm(ll a, ll b){
  return a / std::__gcd(a,b) * b;
}

int main(){
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << lcm(a, lcm(b, c));
  return 0;
}