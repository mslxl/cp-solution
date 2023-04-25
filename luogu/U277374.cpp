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

const int maxn = 2e5 + 17;
const int maxm = 1e6 + 17;
int n, m, k;

#define int ll
struct player {
  int a, b, c;
  int need_k;
} p[maxn];

void solve(const std::size_t testcase) {
  read(n, m, k);
  rep1(i, n) read(p[i].a);
  rep1(i, n) read(p[i].b);
  rep1(i, n) read(p[i].c);

  rep1(i, n) {
    if (p[i].a - p[i].b * m > 0) {
      p[i].need_k = 0;
    } else {
      p[i].need_k = std::ceil(1.0L * (p[i].b * m - p[i].a) / p[i].c);
    }
  }
  std::sort(p + 1, p + 1 + n, [](const player &lhs, const player &rhs) {
      return lhs.need_k < rhs.need_k;
  });
  ll ans = 0;
  ll use_k = 0;
  rep1(i, n){
    if(p[i].need_k + use_k <= k){
      ans++;
      use_k += p[i].need_k;
    }else{
      break;
    }
  }
  std::cout << ans;
}
