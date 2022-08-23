#include <array>

#define lowbit(x) ((-x) & x)

const int bit_size = 4000;
std::array<std::array<int, bit_size>, bit_size> bit;

int prefix_sum(int x, int y) {
  int s = 0;
  for (int i = x; i > 0; i -= lowbit(i)) {
    for (int j = y; j > 0; j -= lowbit(i)) {
      s += bit[i][j];
    }
  }
  return s;
}

void add(int x, int y, int z) {
  for (int i = x; i <= bit_size; i += lowbit(i))
    for (int j = y; j <= bit_size; j += lowbit(j))
      bit[i][j] += z;
}

int sum(int x, int y, int w, int h) {
  return prefix_sum(x + w, y + h) - prefix_sum(x - 1, y + h) -
         prefix_sum(x + w, y - 1) + prefix_sum(x - 1, y - 1);
}