#include <cmath>
#include <iostream>

typedef long long ll;
int bx, by, hx, hy;
ll map[50][50] = {0};

constexpr bool is_avil(int x, int y) {
  return !(x < 0 || y < 0 || x > bx || y > by ||               // 越界
           (x == hx && y == hy) ||                             // 马
           (std::abs(x - hx) == 2 && std::abs(y - hy) == 1) || // 马儿跳
           (std::abs(x - hx) == 1 && std::abs(y - hy) == 2));  // 马儿跳
}

ll dfs(int x, int y) {
  if (x == bx && y == by)
    return 1;
  else if (map[x][y] != 0)
    return map[x][y];

  ll down = 0, right = 0;
  if (is_avil(x + 1, y))
    right = dfs(x + 1, y);
  if (is_avil(x, y + 1))
    down = dfs(x, y + 1);
  map[x][y] = down + right;
  return map[x][y];
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> bx >> by >> hx >> hy;

  std::cout << dfs(0, 0);
  return 0;
}
