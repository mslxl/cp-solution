#include <bits/stdc++.h>
int main() {
  int *road;
  int l, m;
  std::cin >> l >> m;
  road = new int[l + 2];
  std::memset(road, 0, (l + 2) * sizeof(int));
  while (m--) {
    int s, e;
    std::cin >> s >> e;
    road[s]--;
    road[e+1]++;
  }
  long long result = 0;
  int flag = 0;
  for (int i = 0; i < l + 1; i++) {
    flag += road[i];
    if (flag >= 0) {
      result++;
    }
  }
  std::cout << result;
}
