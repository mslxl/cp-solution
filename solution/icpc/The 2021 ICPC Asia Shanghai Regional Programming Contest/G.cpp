// 自分の得意な言語で
// Let's チャレンジ！！

// clang-format off
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
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  rep1(i, t) solve(t);
  return 0;
}
// clang-format on

const int maxn =  1e5 + 17;
ll dp[maxn];
ll size[maxn];
std::vector<int> g[maxn];

const int modd = 998244353;

int n;

void dfs(int u, int fa){
  int cnt = 0;
  dp[u] = 1;
  for(auto v: g[u]){
    if(v == fa) continue;
    dfs(v,u);
    if(size[v] % 2 == 0){
      size[u]++;
    }
    dp[u] = dp[u] * dp[v] % modd;
  }

  for(int i = 1; i <= size[u]; i+=2){
    dp[u] = dp[u] * i % modd;
  }

}

void solve(const std::size_t testcase) {
  std::cin >> n;
  rep1(i, n-1){
    int a,b;
    std::cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(1,0);
  std::cout << dp[1];
}
