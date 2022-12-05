#include <iostream>
#include <string>
#include <vector>

int isX(const std::vector<std::string> &map, int x, int y) {
  const char ch = map[y][x];
  int cnt = 0;
  for (int offset = 1; x - offset >= 0 && x + offset < map[0].size() &&
                       y + offset < map.size() && y - offset >= 0;
       offset++) {
    if (map[y - offset][x - offset] == ch && map[y-offset][x + offset]  == ch&& map[y+offset][x - offset] == ch && map[y + offset][x + offset] == ch){
      cnt++;
    }else{
      break;
    }
  }
  return cnt;
}
int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> map(n);
  std::getline(std::cin, map[0]);
  for (int i = 0; i < n; i++) {
    std::getline(std::cin, map[i]);
  }
  int cnt = 0;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cnt += isX(map, c, r);
    }
  }
  std::cout << cnt;

  return 0;
}