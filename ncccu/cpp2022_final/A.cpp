#include<bits/stdc++.h>
using ll = long long;

int main(){
  ll a,b, x;
  ll ans = 0;
  std::cin >> a >> b >> x;
  for(int i = 1; i * i * i <= b; i++){
    ll value = i * i * i;
    if(a <= value && value <= b && value % x == 0){
      ans++;
    }
  }
  std::cout << ans;
  return 0;
}
