#include <bits/stdc++.h>
#include <cmath>

const int maxn = 2e3 + 17;
const int maxhw = maxn;

int n, q; // 增、删点次数
int wx, wy;
int a, b; // 视窗的纵长、横长
int c, d; // 当前视窗的纵长、横长
int h, w; // 画板的行数、列数

int canvas[maxhw][maxhw];
int pre[maxhw][maxhw];

void build() {
  for (int y = 1; y <= h; y++) {
    for (int x = 1; x <= w; x++) {
      pre[y][x] = 
          pre[y - 1][x] + pre[y][x - 1] - pre[y - 1][x - 1] + canvas[y][x];
    }
  }
}

int at(int y, int x) {
  if (x <= 0)
    x = 0;
  if (y <= 0)
    y = 0;
  if (x > w)
    x = w;
  if (y > h)
    y = h;

  auto v = pre[y][x];
  return v;
}

int main() {
  std::cin >> n >> q;
  std::cin >> a >> b;
  c = a, d = b;
  std::cin >> h >> w;

  for (int i = 0; i < n; i++) {
    int op, x, y;
    std::cin >> op >> y >> x;
    assert(op == 1);
    canvas[y][x] = !canvas[y][x];
  }
  build();

  wx = wy = 1;

  for (int i = 0; i < q; i++) {
    int op;
    std::cin >> op;
    if (op == 4) {
      std::cout << at(wx + c-1, wy + d-1) - at(wx - 1, wy + d-1) -
                       at(wx + c-1, wy - 1) + at(wx - 1, wy - 1)
                << "\n";
    } else if (op == 2) {
      int t;
      std::cin >> t;
      if(c + a * t / 10 < 1 || d + b * t / 10 < 1)
        continue;
      
      c = c + a * t / 10;
      d = d + b * t / 10;
    } else if(op == 3){
      int p, v;
      std::cin >> p >> v;
      if(p == 1) wx-=v;
      else if(p == 2) wx+=v;
      else if(p == 3) wy-=v;
      else if(p == 4) wy+=v;
    }
  }

  return 0;
}