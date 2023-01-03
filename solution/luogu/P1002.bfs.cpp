#include <cmath>
#include <iostream>
#include <queue>

typedef long long ll;
int bx, by, hx, hy;
ll mem[50][50] = {0};
bool vis[50][50] = {false};

constexpr bool is_avil(int x, int y) {
  return !(x < 0 || y < 0 || x > bx || y > by ||               // 没越界
           (x == hx && y == hy) ||                             // 马
           (std::abs(x - hx) == 2 && std::abs(y - hy) == 1) || // 马儿跳
           (std::abs(x - hx) == 1 && std::abs(y - hy) == 2));  // 马儿跳
}

void bfs() {
  std::queue<std::pair<int, int>> queue;
  mem[bx][by] = 1;
  queue.push(std::make_pair(bx, by));

  while (!queue.empty()) {
    auto &pos = queue.front();
    queue.pop();
    int x = pos.first, y = pos.second;
    if (!vis[x][y]) {
      if (is_avil(x - 1, y)) {
        mem[x - 1][y] += mem[x][y];
        queue.push(std::make_pair(x - 1, y));
      }
      if (is_avil(x, y - 1)) {
        mem[x][y - 1] += mem[x][y];
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
  std::cout << mem[0][0];
  return 0;
}
