#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

char map[202][202];
int a[202][202];
int b[202][202];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int yx, yy, mx, my;

void getmap() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
      if (map[i][j] == 'Y') {
        yx = i;
        yy = j;
      } else if (map[i][j] == 'M') {
        mx = i;
        my = j;
      }
    }
}

struct node {
  int x, y;
};

void bfs(int x, int y, int num[202][202]) {
  queue<node> q;
  node aa, bb;
  aa.x = x;
  aa.y = y;
  num[x][y] = 0;
  q.push(aa);
  while (!q.empty()) {
    bb = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      aa.x = bb.x + dx[i];
      aa.y = bb.y + dy[i];
      if (aa.x >= 0 && aa.x < n && aa.y >= 0 && aa.y < m &&
          num[aa.x][aa.y] == 0 && map[aa.x][aa.y] != '#') {
        num[aa.x][aa.y] = num[bb.x][bb.y] + 1;
        q.push(aa);
      }
    }
  }
}
int main() {
  while (cin >> n >> m) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    getmap();
    bfs(yx, yy, a);
    bfs(mx, my, b);
    int minn = 1000000;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (map[i][j] == '@' && b[i][j] != 0)
          minn = min(minn, a[i][j] + b[i][j]);
    cout << minn * 11 << endl;
  }
  return 0;
}
