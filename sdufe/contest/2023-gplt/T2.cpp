#include <bits/stdc++.h>

bool isPrime(int v) {
  if (v == 1) return false;
  for (int i = 2; i * i <= v; i++) {
    if (v % i == 0) return false;
  }
  return true;
}

int m[40][40];
int n, k;

int getMid(int x, int y) {
  int idx = std::ceil(1.0 * k * k / 2);
  int i = 1;
  std::vector<int> seq(1);

  for (int xx = 0; xx < k; xx++) {
    for (int yy = 0; yy < k; yy++) {
      seq.push_back(m[x + xx][y + yy]);
    }
  }
  std::sort(seq.begin() + 1, seq.end());
  return seq[idx];
}

int main() {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> m[i][j];
    }
  }
  int ans = 0;
  for (int x = 1; x + k <= n + 1; x++) {
    for (int y = 1; y + k <= n + 1; y++) {
      int mid = getMid(x, y);
      // std::cerr << "x " << x << ",y " << y << ", mid = " << mid << std::endl;
      if (isPrime(mid)) {
        ans++;
      }
    }
  }
  std::cout << ans;
}
