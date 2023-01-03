#include <bits/stdc++.h>
#include <cassert>
#include <cmath>

void slove() {
  int n;
  std::cin >> n;
  int op = (n+1)/2;
  
  std::cout << op << "\n";
  int src = n * 3 - 1;
  int dst = 1;
  for (int i = 0; i < op; i++) {
    if ((dst - 2) % 3 == 0)
      dst++;
    std::cout << dst << " " << src << "\n";
    src -= 3;
    dst += 3;
  }
}
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    slove();
  }
  return 0;
}