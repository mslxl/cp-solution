// 自分の得意な言語で
// Let's チャレンジ！！

// clang-format off
#include <bits/stdc++.h> 
#include <limits>
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
#define int ll

const int M = 3e5 + 5;
const int N = 500 + 5;
const int INF = std::numeric_limits<int>::max();
ll n, m, r;

struct DiscountCard {
  int d, k, c;
} ca[N];
struct RideRec {
  int p, q;
} re[M];
int a[M], b[M];
int tot;
int dp[M];

void solve(const std::size_t testcase) {
  read(n, m, r);
  rep1(i, n) { read(ca[i].d, ca[i].k, ca[i].c); }

  rep1(i, m) {
    read(re[i].p, re[i].q);
    dp[i] = INF;
    rep1(j, re[i].q) { a[++tot] = re[i].p; }
  }
  std::sort(a + 1, a + 1 + tot);
  for (int i = 1; i <= tot; i++)
    dp[i] = INF;
  for (int i = 1; i <= n; i++)
    b[i] = 1;
  for (int i = 1; i <= tot; i++) {
    dp[i] = dp[i - 1] + r;         //  第 i 次骑行不用卡
    for (int j = 1; j <= n; j++) { // 搜索所有的骑行劵，编号记为 j
                                   // 找到第 j 种劵能影响到的左边界
      while (a[b[j]] + ca[j].d <= a[i] // 在第 b[j] 次租车的当天用第 j 个劵，在第 i 天刚好能用这个卷
             || b[j] + ca[j].k <= i    // 在而且次数也没过限制
      ) {
        b[j]++;
      }
      dp[i] = std::min(dp[i], dp[b[j] - 1] + ca[j].c);
    }
  }
  std::cout << dp[tot];
}
