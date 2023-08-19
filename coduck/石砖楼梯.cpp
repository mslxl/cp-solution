#include <bits/stdc++.h>
using ll = unsigned long long;

bool check(ll n, ll x) { return (n * (n + 1)) >= x * 2; }

int main() {
  ll x;

  while (std::cin >> x) {
    ll L = 1, R = x;
    while (L < R) {
      ll mid = (L + R) / 2;
      if (check(mid, x)) {
        R = mid;
      } else {
        L = mid + 1;
      }
    }
    std::cout << (L * (L + 1))/2 - x << "\n";
  }

  return 0;
}