#include<iostream>
using ll = long long;

ll ksc(ll a, ll b, ll p){
  ll ans = 0;
  while(b != 0){
    if(b & 1) ans = (a + ans) % p;
    a = (a + a) % p;
    b >>= 1;
  }
  return ans % p;
}

int main(){
  ll a, b, p;
  std::cin >> a >> b >> p;
  std::cout << ksc(a, b, p);
  return 0;
}