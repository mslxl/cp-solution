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

#define int ll
const int maxn = 1e5 + 17;
int a[maxn];
int sum[maxn];
int pre[maxn];
int n;

void solve(const std::size_t testcase) {
  read(n);
  int flag = 0;
  rep1(i, n) {
    read(a[i]);
    sum[i] = (sum[i - 1] + a[i]) % n;
  }
  rep1(i, n) {
    if (sum[i] == 0) {
      std::cout << i << "\n";
      for (int j = 1; j <= i; j++) {
        std::cout << a[j] << "\n";
      }
      flag = 1;
      break;
    }
    if (flag)
      break;
  }
  if (flag)
    return;
  rep1(i, n) {
    if (pre[sum[i]]) {
      std::cout << i - pre[sum[i]] << "\n";
      int ans = pre[sum[i]] + 1;
      while (ans <= i) {
        std::cout << a[ans] << "\n";
        ans++;
      }
      break;
      flag = 1;
    }
    if (flag)
      break;
    pre[sum[i]] = i;
  }
}
