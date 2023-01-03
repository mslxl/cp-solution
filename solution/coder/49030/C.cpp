#include <algorithm>
#include <bits/stdc++.h>
using ll = long long;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  ll n;
  std::cin >> n;
  std::vector<std::pair<ll,ll>> a(n), b(n);
  for (int i = 0; i < n; i++){
    std::cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 0; i < n; i++){
    std::cin >> b[i].first;
    b[i].second = i;
  }

  std::sort(b.begin(), b.end());
  std::sort(a.begin(), a.end());

  ll w = 0, l = 0, e = 0;
  do {
    ll wp = 0, lp = 0;
    for (int i = 0; i < n; i++) {
      if (a[i].first > b[i].first)
        wp++;
      else if (a[i].first < b[i].first)
        lp++;
    }
    if (wp > lp)
      w++;
    else if (wp < lp)
      l++;
    else
      e++;

  } while (std::next_permutation(b.begin(), b.end()));
  printf("%lld %lld %lld", w, l, e);

  return 0;
}
