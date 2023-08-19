#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#include <algorithm>
#include <map>
#include <math.h>
#include <set>
#include <tuple>
#include <vector>
ll qpow(ll a, ll b, ll mod) {
  ll ans = 1;
  while (b > 0) {
    if (b & 1)
      ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0)
    return x = 1, y = 0, a;
  ll r = exgcd(b, a % b, x, y);
  tie(x, y) = make_tuple(y, x - (a / b) * y);
  return r;
}

const int maxn = 1e6;
bool vis[maxn + 5];
int prime[maxn + 5], cnt = 0, phi[maxn + 5];
void get_EulerFunction() {
  for (int i = 2; i <= maxn; i++) {
    if (!vis[i])
      prime[++cnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= cnt && i * prime[j] <= maxn; j++) {
      int x = i * prime[j];
      vis[x] = 1;
      if (i % prime[j] == 0) {
        phi[x] = phi[i] * prime[j];
        break;
      }
      phi[x] = phi[i] * (prime[j] - 1);
    }
  }
}

int main() {
  ll t;
  t = 1;
  //    cin>>t;
  get_EulerFunction();
  vector<ll> arr(10004);
  for (int i = 1; i <= 10000; i++) {
    int k = 1;
    ll ans = 0;
    for (int j = 1; j <= maxn; j++) {
      if (prime[j] > i)
        break;
      ans += prime[j];
      while (ans > i) {
        ans -= prime[k];
        k++;
      }
      if (ans == i)
        arr[i]++;
    }
  }
  while (t--) {
    while (1) {
      ll n;
      cin >> n;
      if (n == 0)
        break;
      cout << arr[n] << endl;
    }
  }
  return 0;
}