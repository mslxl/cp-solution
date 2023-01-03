#include <bits/stdc++.h>
using ll = long long;
const auto cannot = "Ginger666";
int main() {
  // std::ios::sync_with_stdio(false);
  // std::cin.tie(nullptr);
  // std::cout.tie(nullptr);

  ll n, k;
  std::cin >> n >> k;
  std::vector<ll> c(k);

  for (int i = 0; i < k; i++) {
    std::cin >> c[i];
  }

  std::sort(c.begin(), c.end());

  if (k == 1) {
    std::cout << cannot;
    return 0;
  }

  ll mod = n % 3;
  if (mod == 0) {
    std::cout << (c[0] * 2 + c[1]) * (n/3);
  }else if(mod == 1){
    std::cout << (c[0] * 2 + c[1]) * (n/3) + c[1];
  }else if(mod == 2){
    std::cout << (c[0] * 2 + c[1]) * (n/3) + + c[0] + c[1] ;
  }
  return 0;
}
