#include <bits/stdc++.h>

template <typename T>
inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x) {
  char c;
  T f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-')
      f = -1;
  x = (c & 15);
  while (isdigit(c = getchar()))
    x = (x << 1) + (x << 3) + (c & 15);
  x *= f;
}
template <typename T, typename... A> inline void read(T &value, A &..._t) {
  read(value), read(_t...);
}

using ll = long long;

const int maxn = 2021;
const int maxm = 1e5 + 17;
const ll INF = (1ll << 60);

struct edge {
  int next, to;
} e[maxm];

int head[maxn], idx = 0;

void add_edge(int x, int y) {
  e[++idx].next = head[x];
  head[x] = idx;
  e[idx].to = y;
}

int n;

int hp[maxn], size[maxn];
ll dp[maxn][maxn][2];
ll temp[maxn];

void dfs(int x){
  for(int i = 0; i <=n; i++){
    dp[x][i][0] = dp[x][i][1] = INF;
  }
  dp[x][0][1] = hp[x];
  dp[x][1][0] = 0;
  size[x] = 1;
  for(int i = head[x]; i != 0; i = e[i].next){
    const int v = e[i].to;
    dfs(v);

    for(int j = 0 ; j <= size[x] + size[v]; j++){
      temp[j] = INF;
    }

    for(int j = 0; j <= size[x]; j++){
      for(int k = 0; k <= size[v]; k++){
        temp[j+k] = std::min(temp[j+k], dp[x][j][0] + std::min(dp[v][k][0], dp[v][k][1]));
      }
    }


    for(int j = 0; j <= size[x] + size[v]; j++){
      dp[x][j][0] = temp[j];
      temp[j] = INF;
    }

    for(int j = 0; j <= size[x]; j++){
      for(int k = 0; k <= size[v]; k++){
        temp[j+k] = std::min(temp[j+k], dp[x][j][1] + std::min(dp[v][k][0], dp[v][k][1] + hp[v]));
      }
    }
    for(int j = 0; j <= size[x] + size[v]; j++){
      dp[x][j][1] = temp[j];
      temp[j] = INF;
    }
    size[x] += size[v];
  }
}

void solve() {
  read(n);
  for(int i = 2; i <= n; i++){
    int p;
    read(p);
    add_edge(p, i);
  }
  for(int i = 1; i <= n; i++){
    read(hp[i]);
  }
  dfs(1);
  for(int i = 0; i <= n; i++){
    std::cout << std::min(dp[1][i][0], dp[1][i][1]) << " ";
  }
  std::cout << std::endl;

  std::memset(head, 0, sizeof(head));
  idx = 0;
}

int main() {
  int T;
  read(T);
  while (T--) {
    solve();
  }
}
