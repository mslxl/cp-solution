#include <iostream>
using namespace std;
#include <algorithm>
#include <math.h>
#include <vector>

#define ll long long
class node {
public:
  ll x, y, z;
  bool operator<(node &n) {
    if (this->x == n.x) {
      return this->y > n.y;
    }
    return this->x > n.x;
  }
};

vector<vector<ll>> v(1000001);
vector<ll> vis(1000001);

ll arr[1000001];

void dfs(int x, int d) {
  ll ans = 0;
  for (int i = 0; i < v[x].size(); i++) {
    ll p = v[x][i];
    if (vis[p] == 0) {
      vis[p] = 1;
      dfs(p, d + 1);
    }
  }
  arr[x] = d;
}

int main() {
  int n, q;
  cin >> n;
  q = 1;
  vis[q] = 1;
  for (int i = 1; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  arr[q] = 0;
  dfs(q, 0);
  ll x = 0;
  ll maxn = 0;
  for (int i = 1; i <= n; i++) {
    maxn = max(arr[i], maxn);
  }
  cout << maxn + 1 << endl;

  return 0;
}