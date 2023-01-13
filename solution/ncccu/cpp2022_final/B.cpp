#include <bits/stdc++.h>
#include <cmath>
#include <set>
using ll = long long;
const int maxn = 1e6 + 17;
std::multiset<ll> A;
ll max = 0;

int main() {
  ll N;
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    ll V;
    std::cin >> V;
    A.insert(V);
    if (i == 0) {
      max = std::max(max, V);
      std::cout << "0 0\n";
      continue;
    }
    ll cnt = 0;
    ll sum = 0;
    ll pow = V;
    for (int i = 2; pow <= max; i++) {
      pow *= V;
      if (A.count(pow)) {
        ll num = A.count(pow);
        cnt += num;
        sum += pow * num;
      }
    }
    std::cout << cnt << " " << sum << "\n";
    max = std::max(max, V);
  }
  return 0;
}
