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
  read(t);
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  rep1(i, t) solve(t);
  return 0;
}
// clang-format on
bool check(int k, const std::vector<std::vector<int>> &a, ll n, ll m) {
  std::vector<std::vector<int>> pre(n + 1, std::vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pre[i][j] =
          (a[i][j] >= k) + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    }
  }
  for (int i = k; i <= n; i++) {
    for (int j = k; j <= m; j++) {
      int x = i - k + 1, y = j - k + 1;
      if (pre[i][j] + pre[x - 1][y - 1] - pre[x - 1][j] - pre[i][y - 1] ==
          k * k)
        return true;
    }
  }
  return false;
}

void solve(const std::size_t testcase) {
  ll n, m;
  read(n, m);
  std::vector<std::vector<int>> mp(n + 1, std::vector<int>(m + 1));
  rep1(i, n) {
    rep1(j, m) { read(mp[i][j]); }
  }
  int r = std::min(n, m);
  int l = 1;
  int ans = 0;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if(check(mid, mp, n,m)){
      ans = std::max(ans, mid);
      l = mid + 1;
    }else{
      r = mid - 1;
    }
  }
  std::cout << ans  << std::endl;
}
