#include <bits/stdc++.h>
using namespace std;
int fa[1010], num[1010];
void find(int x) {
  num[x]++;
  if (fa[x] != x)
    find(fa[x]);
}
int main() {
  ios::sync_with_stdio(false);
  int n, x, y, sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    find(x);
    fa[y] = x;
  }
  for (int i = 1; i <= n; i++)
    sum += num[i] + 1;
  cout << sum;
  return 0;
}