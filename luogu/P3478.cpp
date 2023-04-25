// 自分の得意な言語で
// Let's チャレンジ！！

// clang-format off
#include <algorithm>
#include <bits/stdc++.h> 
using ll = long long; using ul = unsigned long long; using ld = long double;
template <typename T> inline typename std::enable_if<std::is_integral<T>::value>::type read(T &x){ char c;T f=1; while(!isdigit(c=getchar())) if(c=='-')f=-1; x=(c&15); while(isdigit(c=getchar())) x= (x<<1) + (x<<3) + (c&15); x*=f; } template <typename T, typename... A> inline void read(T &value, A &..._t) { read(value), read(_t...); }
void solve(const std::size_t testcase);
#define rep(NAME, MAX) for(decltype(MAX) NAME = 0; NAME < MAX; NAME++)
#define rep1(NAME, MAX) for(decltype(MAX) NAME = 1; NAME <= MAX; NAME++)
#define repv0(NAME, START) for(decltype(START) NAME = START; NAME >= 0; NAME--)
#define repv1(NAME, START) for(decltype(START) NAME = START; NAME >= 1; NAME--)
int main() {
  std::size_t t = 1;
  // read(t);
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  rep1(i, t) solve(t);
  return 0;
}
const int maxn = 1e6 + 17;

struct edge{
  int to,next;
}e[maxn * 2];

int head[maxn], eid = 0;

void add_edge(int u, int v){
  eid++;
  e[eid].to = v;
  e[eid].next = head[u];
  head[u] = eid;
}
void add_biedge(int u, int v){
  add_edge(u, v);
  add_edge(v, u);
}

#define int ll
int n;
int inde[maxn];
int size[maxn];
int rt = 0;
int dp[maxn];

int upd_size(int x, int fa, int dep) {
  size[x] = 1;
  int value = dep;
  for (int i = head[x]; i != 0; i = e[i].next) {
    const int v = e[i].to;
    if (v == fa)
      continue;
    value += upd_size(v, x, dep + 1);
    size[x] += size[v];
  }
  return value;
}

void dfs(int x, int fa){
  dp[x] = dp[fa] - size[x] + n - size[x] ;

  for (int i = head[x]; i != 0; i = e[i].next) {
    const int v = e[i].to;
    if(v == fa) continue;
    dfs(v, x);
  }
}

void solve(const std::size_t testcase) {
  read(n);
  rep(i, n-1) {
    int u, v;
    read(u, v);
    add_biedge(u, v);
    inde[v]++;
  }
  rt = 1;

  dp[rt] = upd_size(rt, 0, 0);

  for (int i = head[rt]; i != 0; i = e[i].next) {
    const int v = e[i].to;
    dfs(v, rt);
  }

  std::cout << (std::max_element(dp+1, dp+1+n) - dp);
}
