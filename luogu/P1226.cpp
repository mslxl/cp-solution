#include <bits/stdc++.h>

using namespace std;
template <typename T> T pow(T a, T b, T p) {
  T ans = 1;
  for (; b; b >>= 1LL) {
    if (b & 1)
      ans = ans * a % p;
    a = a * a % p;
  }
  return ans;
}

typedef long long ll;

int main() {
  ll a, b, p;
  cin >> a >> b >> p;
  printf("%lld^%lld mod %lld=%lld", a, b, p, pow(a, b, p));
  return 0;
}
