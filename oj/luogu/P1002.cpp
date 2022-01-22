#include <cmath>
#include <iostream>
#include <queue>

typedef long long ll;
int bx, by, hx, hy;
ll map[20][20] = {0};
bool vis[20][20] = {false};

constexpr bool is_avil(int x, int y) {
  return !(x < 0 || y < 0 || x > bx || y > by ||               // 没越界
           (x == hx && y == hy) ||                             // 马
           (std::abs(x - hx) == 2 && std::abs(y - hy) == 1) || // 马儿跳
           (std::abs(x - hx) == 1 && std::abs(y - hy) == 2));  // 马儿跳
}

void bfs() {
  std::queue<std::pair<int, int>> queue;
  map[bx][by] = 1;
  queue.push(std::make_pair(bx, by));

  while (!queue.empty()) {
    auto &pos = queue.front();
    queue.pop();
    int x = pos.first, y = pos.second;
    if (!vis[x][y]) {
      if (is_avil(x - 1, y)) {
        map[x - 1][y] += map[x][y];
        queue.push(std::make_pair(x - 1, y));
      }
      if (is_avil(x, y - 1)) {
        map[x][y - 1] += map[x][y];
        queue.push(std::make_pair(x, y - 1));
      }
      vis[x][y] = true;
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> bx >> by >> hx >> hy;
  bfs();
  std::cout << map[0][0];
  return 0;
}
