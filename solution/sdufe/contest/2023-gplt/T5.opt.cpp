#include <bits/stdc++.h>

int main() {
  int Y;
  std::cin >> Y;
  std::cout << "1\n" << Y << "\n";
  int cnt = 0;
  for (int i = 0; i <= Y; i++) {
    if ((i | Y) == Y) cnt++;
  }
  std::cout << cnt << "\n";
  for (int i = 0; i <= Y; i++) {
    if ((i | Y) == Y) std::cout << i << "\n";
  }
  return 0;
}