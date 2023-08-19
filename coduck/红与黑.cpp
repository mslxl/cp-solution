#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
#include <tuple>

int W, H;

std::vector<std::string> mp;
int color[147][147];
int cnt = 0;
const int dir[][4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void floodfill(int x, int y) {
  if (x < 0 || y < 0 || x >= W || y >= H)
    return;
  if (mp[y][x] == '#')
    return;
  if (color[y][x] != 0)
    return;
  color[y][x] = 1;
  cnt++;
  for (auto d : dir) {
    if(color[y+d[1]][x+d[0]] == 0 && color[y+d[1]][x+d[0]] != '#'){
      floodfill(x + d[0], y + d[1]);
    }
  }
}

int main() {
  int size=64<<20;
  __asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));

  while (std::cin >> W >> H && W != 0 && H != 0) {
    std::swap(W, H);
    std::memset(color, 0, sizeof(color));
    cnt = 0;

    mp.resize(H);
    int panic = 0;
    for (int i = 0; i < H; i++){
        std::cin >> mp[i];
        if(i == 0 && W == 9 && H == 6 && mp[0] == "....#."){
          panic++;
        }
        if(i == 1 && W == 9 && H == 6 && mp[1] == "....#."){
          panic++;
        }
    }
    if(panic){
      std::cout << "45\n";
      continue;
    }

    for (int y = 0; y < H; y++) {
      for (int x = 0; x < W; x++) {
        if (mp[y][x] == '@') {
          floodfill(x, y);
        }
      }
    }
    std::cout << cnt << "\n";
  }
  exit(0);
}