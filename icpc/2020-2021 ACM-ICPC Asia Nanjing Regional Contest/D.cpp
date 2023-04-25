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
  read(t);
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  rep1(i, t) solve(t);
  return 0;
}
// clang-format on

const int maxn = 2e5 + 10;

std::vector<std::pair<int, int>> es;
std::map<std::pair<int, int>, int> mp;

// 存生成树用的()
struct Edge {
  int to;
  int next;
} edges[maxn << 2];

int head[maxn], idx;
int deg[maxn];

void add(int u, int v) {
  edges[idx] = {v, head[u]};
  head[u] = idx++;
  edges[idx] = {u, head[v]};
  head[v] = idx++;
}

int pre[maxn];
int chose[maxn];

// 并查集
int fi(int x) { return x == pre[x] ? x : pre[x] = fi(pre[x]); }

void dfs(int u, int fa, int sig) {
  pre[u] = sig;
  for (int i = head[u]; ~i; i = edges[i].next) {
    int v = edges[i].to;
    if (v == fa)
      continue;
    dfs(v, u, sig);
  }
}

// 多测清数据
void init(int n, int m) {
  mp.clear();
  es.clear();
  for (int i = 0; i <= n; i++) {
    head[i] = -1;
    deg[i] = 0;
    pre[i] = i;
  }

  for (int i = 0; i <= m; i++) {
    chose[i] = 0;
  }
  idx = 0;
}

void solve(const std::size_t testcase) {
  int n, m;
  read(n, m);
  init(n, m);
  for (int i = 0; i < m; i++) {
    int u, v;
    read(u, v);
    if (u > v)
      std::swap(u, v);
    es.push_back({u, v});
  }
  std::sort(es.begin(), es.end());
  es.erase(std::unique(es.begin(), es.end()), es.end()); // 删除重边
  m = int(es.size());
  // 使用并查集建立生成树
  for (int i = 0; i < m; i++) {
    int u = es[i].first;
    int v = es[i].second;
    mp[{u, v}] = mp[{v, u}] = i;
    int fu = fi(u), fv = fi(v);
    if (fu != fv) {
      add(u, v);
      pre[fu] = fv;
      deg[u]++;
      deg[v]++;
      chose[i] = 1;
    }
  }

  // 不连通直接输出 NO
  int flag = 0;
  for (int i = 2; i <= n; i++) {
    if (fi(i) != fi(1))
      flag = 1; // 不连通
  }
  if (flag) {
    std::cout << "No\n";
    return;
  }

  // 如果所有的度数都小于n/2，那么不需要调整，直接输出答案
  int rt = -1;
  for (int i = 1; i <= n; i++) {
    if (deg[i] > n / 2) {
      rt = i;
      break;
    }
  }
  if (rt == -1) {
    std::cout << "Yes\n";
    for (int i = 0; i < m; i++) {
      if (chose[i]) {
        std::cout << es[i].first << " " << es[i].second << "\n";
      }
    }
    return;
  }

  // 以rt为根，将其所有的子树加到一个集合里
  for (int i = 1; i <= n; i++)
    pre[i] = i;
  for (int i = head[rt]; ~i; i = edges[i].next) {
    dfs(edges[i].to, rt, edges[i].to);
  }
  for (int i = 0; i < m; i++) {
    if (chose[i])
      continue; // 这条边在当前生成树中已存在，跳过
    int u = es[i].first, v = es[i].second;
    int fu = fi(u), fv = fi(v);
    if (u == rt || v == rt)
      continue; // 这是和根相连的点，要么已使用，要么添加后会增加度数
    if (fu == fv)
      continue; // 这条边的两顶点同属于一棵子树，使用只会增加度数

    // 用u-v边替换掉rt-fu边
    deg[rt]--;
    deg[u]++;
    deg[v]++;
    deg[fu]--;

    if (deg[u] > n / 2 || deg[v] > n / 2) { // 添加u-v边后，u,v两节点是否不合法
      // 原本从 rt-fv 连接子树，换成 rt-fu
      deg[fu]++;
      deg[fv]--;
      if (deg[u] > n / 2 || deg[v] > n / 2) {
        // u-v 仍不合法，把原来的边恢复，再去尝试另一条连接两颗子树的边
        deg[rt]++;
        deg[u]--;
        deg[v]--;
        deg[fv]++;
        continue;
      } else {
        // u -v 合法，也就是说成功把根的度数降低了1
        pre[fv] = fu;
        chose[i] = 1;
        chose[mp[{rt, fv}]] = 0;
      }
    } else {
      // u -v 合法，也就是说成功把根的度数降低了1
      pre[fu] = fv;
      chose[i] = 1;
      chose[mp[{rt, fu}]] = 0;
    }
    if(deg[rt] <= n/2) break; //如果现在根的度数满足要求，就不需要继续进行了
  }
  if(deg[rt] <= n/2){
    std::cout << "Yes\n";
    for(int i = 0 ; i< m; i++){
      if(chose[i]){
        std::cout << es[i].first << " " << es[i].second << "\n";
      }
    }

  }else{
    std::cout << "No\n";
  }
}
