#include <bits/stdc++.h>
const int maxn = 10;
int seq[maxn];
int n;
int main() {

  while (std::cin >> n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int num;
      std::cin >> num;
      seq[num]++;
    }
    std::cout << (std::max(seq[1] - seq[3], 0) + 3 + seq[2] * 2) / 4 + seq[3] +
                     seq[4];
  }
  return 0;
}
