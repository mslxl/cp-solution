#include <bits/stdc++.h>
#pragma optimize(2)

const int maxn = 1e7 + 17;

using ll = long long;
int n;
ll  X, Y, P, a[maxn];
int main() {
  #define int ll
  std::cin >> n >> a[1] >> X >> Y >> P;
  for (int i = 2; i <= n; i++) {
    a[i] = std::max(1LL, (X *a[i - 1] + Y) % P);
  }
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] ^ a[i];
  }

  std::unordered_map<ll, int> mp;
  mp[0] = 1;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += mp[a[i]];
    mp[a[i]]++;
  }
  if (ans == 0) {
    std::cout << "liar";
  } else {
    std::cout << ans;
  }

  return 0;
}