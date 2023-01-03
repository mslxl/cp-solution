#include <bits/stdc++.h>

int main() {
  int num, remain = 1;
  std::cin >> num;
  if (num == 0){
    std::cout << num;
  }
  while (true) {
    if (num >= remain) {
      remain *= 8;
      continue;
    }
    remain /= 8;
    if (remain == 0)
      break;
    std::cout << num / remain;
    if (num >= remain) {
      num %= remain;
    }
  }
  return 0;
}