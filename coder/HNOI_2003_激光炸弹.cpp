#include <bits/stdc++.h>
int n, R;
const int maxloc = 5e3 + 15;
int map[maxloc][maxloc] = {0};
using ll = unsigned long long;
int main() {
  std::cin >> n >> R;
  for (int i = 0; i < n; i++) {
    int x, y, v;
    std::cin >> x >> y >> v;
    map[y+1][x+1] = v;
  }
  for (int i = 0; i < maxloc; i++) {
    for (int j = 1; j < maxloc; j++) {
      map[i][j] += map[i][j - 1];
    }
  }
  for (int i = 0; i < maxloc; i++) {
    for (int j = 1; j < maxloc; j++) {
      map[j][i] += map[j - 1][i];
    }
  }
  ll ans = 0;
  for (int y = R;y < maxloc; y++) {
    for (int x = R; x < maxloc; x++) {
        ll cup = map[y][x] - map[y - R][x] - map[y][x - R] + map[y - R][x - R];
        ans = std::max(ans, cup);
    }
  }
  std::cout << ans;
  return 0;
}