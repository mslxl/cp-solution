#include <iostream>
typedef unsigned long long ll;
ll modd = 10e8 + 7;

ll ksm(ll a, ll b) {
  ll ans = 1;
  for (; b; b >>= 1LL) {
    if (b & 1)
      ans = ans * a % modd;
    a = a * a % modd;
  }
  return ans;
}
template <typename T> T inv_elem(T a, T p) { return ksm(a, p - 2) % p; }

void solve() {
  ll n, m;
  std::cin >> n >> m;
  ll k = ksm(2ULL, n);
  ll up = (m * ((k - 2 + modd) % modd)) % modd;
  ll inv = inv_elem(k, modd);
  std::cout << ((up * inv) % modd) << std::endl;
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
