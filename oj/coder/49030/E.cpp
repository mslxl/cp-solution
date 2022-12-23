#include <bits/stdc++.h>

using ll = long long;
const ll modd = 998244353;

template <typename T>
T qpow(T a, long long n, long long mod){
    T ans = 1; 
    while (n){
        if (n & 1) ans = (ans * a) % mod; 
        n >>= 1;
        a = (a * a) % mod;
    }
    return ans % mod;
}

int main() {
  ll n;
  std::cin >> n;
  if(n <= 2) {
    std::cout << n;
    return 0;
  }
  ll ans = 1;
  for(ll i = 1; i <= n+2; i++){
    ans = (ans * i) % modd;
  }
  ll inv = qpow(12ll, modd-2, modd);
  std::cout <<(ans * inv) % modd;
  return 0;
}
