#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

int edge[1001][1001], f[1001], n, m;

int main(){
  std::ios::sync_with_stdio(false);
  std::cin >> n >> m;
  memset(edge, 127, sizeof(edge));
  for(int i = 1; i <= m; i++){
    int x,y,z;
    std::cin >> x >> y >> z;
    // edge[x][y] = min(edge[x][y], z);
    // 太迷惑了
    // 干啥呢

    edge[x][y] = z;
  }

  memset(f, 127, sizeof(f));

  f[1] = 0;
  for(int i  = 2; i <= n; i++) {
    for(int j = 1; j <= i; j++) {
      f[i] = std::min(f[i], f[j] + edge[j][i]);
    }
  }
  std::cout << f[n];
  return 0;
}
