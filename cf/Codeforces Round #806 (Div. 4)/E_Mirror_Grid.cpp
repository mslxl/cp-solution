#include <bits/stdc++.h>
int matrix[117][117];
void solve() {
  int n;
  std::memset(matrix, 0, sizeof(matrix));

  scanf("%d", &n);
  if (n == 0) {
    printf("0");
    return;
  }
  int ops = 0;
  int b;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      scanf("%1d", &matrix[y][x]);
    }
  }

  for(int x = 0; x < n; x++){
    int num[2] = {0,0};
    for(int y = 0; y<n;y++){
        num[matrix[y][x]]++;
        num[matrix[n-1-x][y]]++;
        num[matrix[n-1-y][n-1-x]]++;
        num[matrix[n-1-(n-1-x)][n-1-y]]++;
        ops+= std::min(num[0],num[1]);
        num[1] = num[0] = 0;
    }
  }
  std::cout << ops/4 << std::endl;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}