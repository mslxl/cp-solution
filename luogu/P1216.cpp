#include <cstring>
#include <iostream>

const int maxr = 1005;
int r;
int mem[maxr][maxr];
int mm[maxr][maxr];

int main() {
  std::cin >> r;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= i; j++) {
      std::cin >> mem[i][j];
    }
  }
  std::memset(mm, 0, sizeof(mm));

  for (int i = 1; i <= r; i++) {
    mm[r][i] = mem[r][i];
  }

  for (int i = r - 1; i >= 1; i--) {
    // std::cout << "i=" << i << '\t';
    for (int j = 1; j <= i; j++) {
      mm[i][j] = std::max(mm[i + 1][j], mm[i + 1][j + 1]) + mem[i][j];
      // std::cout << mm[i][j] << ' ';
    }
    // std::cout << std::endl;
  }
  std::cout << mm[1][1];

  return 0;
}
