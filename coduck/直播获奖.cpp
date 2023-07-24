#include <bits/stdc++.h>

int n, w;
const int maxn = 1e5 + 17;
int x[maxn];
int bk[600 + 17];

int main() {
  std::cin >> n >> w;
  for (int i = 0; i < n; i++) {
    std::cin >> x[i];

    bk[x[i]]++;
    int idx = std::max(1, (i + 1) * w / 100);
    int ppl = 0;
    for (int j = 600; j >= 0; j--) {
      ppl += bk[j];
      if (ppl - bk[j] < idx && ppl >= idx) {
        std::cout << j << " ";
        break;
      }
    }
  }

  return 0;
}
