#include <bits/stdc++.h>

void solve() {
  long long num, result = 0;
  std::cin >> num;
  std::size_t first_1_pos = -1, second_1_pos = -1, first_0_pos = -1;
  int i = 0;
  for (i = 0; num != 0; i++, num >>= 1) {
    if (num & 1) {
      if (first_1_pos == -1) {
        first_1_pos = i;
      } else if (second_1_pos == -1) {
        second_1_pos = i;
      }
    } else {
      if (first_0_pos == -1) {
        first_0_pos = i;
      }
    }
  }

  if (first_0_pos == -1) {
    first_0_pos = i;
  }
  if (second_1_pos != -1) {
    std::cout << (1 << first_1_pos) << std::endl;
  } else {
    std::cout << ((1 << first_1_pos) | (1 << first_0_pos)) << std::endl;
  }
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
