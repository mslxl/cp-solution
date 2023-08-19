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

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> f(n + 5);
  vector<vector<ll>> v(n + 5);
  for (int i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }
  vector<ll> maxn(n + 5);
  vector<ll> pos(n + 5);
  for (int i = 1; i <= n; i++) {
    maxn[i] = f[i];
    pos[i] = i;
    for (int j = 0; j < v[i].size(); j++) {
      if (maxn[i] < f[v[i][j]]) {
        maxn[i] = f[v[i][j]];
        pos[i] = v[i][j];
      } else if (maxn[i] == f[v[i][j]]) {
        pos[i] = min(pos[i], v[i][j]);
      }
    }
  }

  ll q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    ll x;
    cin >> x;
    cout << pos[x] << " " << maxn[x] << endl;
  }
  return 0;
}