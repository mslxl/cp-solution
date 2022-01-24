#include <cstdio>
#include <cstring>

const int maxn = 1000;
int g[maxn][maxn]; // 邻接表
int indgr[maxn];   // 入度
int res[maxn];

/**
 * 很暴力
 * n 表示一共有几个节点
 * 要求节点连续, 很难满足
 * 故该代码仅作示例
 * */
void toposort(int n) {
  int k = 0;
  for (int i = 1; i <= n; i++) {
    printf("Seach num %d\n", i);
    for (int j = 1; j <= n; j++) { // 找入度为 0 的点
      if (!indgr[j]) {
        res[i] = j; // 记录已处理的点
        indgr[j]--; // 删除入度为 0 的点（置为 -1)
        k = j;
        break;
      }
    }

    for (int j = 1; j <= n; j++) {
      if (g[k][j] == 1) {
        g[k][j] = 0; // 删除对应的边
        indgr[j]--;  // 入度 - 1
      }
    }
  }
}

void output(int n) {
  for (int i = 1; i <= n; i++) {
    printf("%d ", res[i]);
  }
  printf("\n");
}

int main() {
  int data[][2] = {{5, 3}, {5, 6}, {5, 8}, {1, 3}, {6, 3},
                   {8, 3}, {3, 4}, {3, 2}, {7, 2}};
  int n = 8;
  memset(indgr, 0, sizeof(indgr));
  memset(g, 0, sizeof(g));
  for (int i = 1; i <= n; i++) {
    auto &edge = data[i - 1];
    if (!g[edge[0]][edge[1]]) {
      g[edge[0]][edge[1]] = 1;
      indgr[edge[1]]++;
    }
  }
  toposort(n);
  output(n);
  return 0;
}
