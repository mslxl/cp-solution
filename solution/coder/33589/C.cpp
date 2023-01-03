#include <bits/stdc++.h>

const int N = 1e5 + 7;

int n, m;
int k;
int cnt;
int tot;
int u[N], v[N];

void dfs(int p, int k) {
  if (k == 3) {
    u[++tot] = p;
    v[tot] = p + 1;
    return;
  }
  if (k < 3)
    return;
  if (k & 1) {
    u[++tot] = p;
    v[tot] = p + 1;
    u[++tot] = p;
    v[tot] = p + 2;
    dfs(p + 2, k >> 1);
  } else {
    u[++tot] = p;
    v[tot] = p + 1;
    dfs(p + 1, k - 1);
  }
}

int main() {
  scanf("%lld", &k);
  if (k == 2) {
    std::cout << "1";
    return 0;
  }
  dfs(1, k);
  std::cout << tot + 1 << std::endl;
  for (int i = 1; i <= tot; ++i) {
    std::cout << u[i] << " " << v[i] << std::endl;
  }
  return 0;
}