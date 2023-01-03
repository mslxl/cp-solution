//异色格
#include <bits/stdc++.h>

std::vector<std::string> map(8);
int safe[8][8];

void mark_hv(int x, int y) {
  safe[y][x] = 1;
  for (int i = x + 1; i < 8; i++) {
    if (map[y][i] == '.') {
      safe[y][i] = 1;
    } else {
      break;
    }
  }
  for (int i = x - 1; i >= 0; i--) {
    if (map[y][i] == '.') {
      safe[y][i] = 1;
    } else {
      break;
    }
  }

  for (int i = y + 1; i < 8; i++) {
    if (map[i][x] == '.') {
      safe[i][x] = 1;
    } else {
      break;
    }
  }

  for (int i = y - 1; i >= 0; i--) {
    if (map[i][x] == '.') {
      safe[i][x] = 1;
    } else {
      break;
    }
  }
}

void mark_s(int x, int y) {
  safe[y][x] = 1;
  for (int i = 1; x + i < 8 && y + i < 8; i++) {
    int ny = y + i;
    int nx = x + i;
    if (map[ny][nx] == '.') {
      safe[ny][nx] = 1;
    } else {
      break;
    }
  }

  for (int i = 1; x + i < 8 && y - i >= 0; i++) {
    int ny = y - i;
    int nx = x + i;
    if (map[ny][nx] == '.') {
      safe[ny][nx] = 1;
    } else {
      break;
    }
  }

  for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
    int ny = y - i;
    int nx = x - i;
    if (map[ny][nx] == '.') {
      safe[ny][nx] = 1;
    } else {
      break;
    }
  }

  for (int i = 1; x - i >= 0 && y + i < 8; i++) {
    int ny = y + i;
    int nx = x - i;
    if (map[ny][nx] == '.') {
      safe[ny][nx] = 1;
    } else {
      break;
    }
  }
}

int main() {
  std::memset(safe, 0, sizeof(safe));
  for (int i = 0; i < 8; i++) {
    std::string line;
    std::getline(std::cin, line);
    map[i] = line;
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (map[i][j] == 'R') {
        mark_hv(j, i);
      }
      if (map[i][j] == 'B') {
        mark_s(j, i);
      }
    }
  }

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (safe[i][j] == 1) {
        std::cout << 0;
      } else {
        std::cout << 1;
      }
    }
    std::cout << std::endl;
  }
  return 0;
}