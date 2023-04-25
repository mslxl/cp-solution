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

void solve(const std::size_t testcase) {
  int n;
  read(n);
  std::vector<std::string> seq(n);
  rep(i, n) {
    std::cin >> seq[i];
    std::reverse(seq[i].begin(), seq[i].end());
  }

  ll ans = 0;
  auto mappend = [&ans](const std::string lhs,
                        const std::string rhs) -> std::string {
    std::string result;
    int carry = 0;
    int adv_carry = 0;
    for (int i = 0, len = std::max(lhs.size(), rhs.size()); i < len; i++) {
      int lnum = i < lhs.size() ? lhs[i] - '0' : 0;
      int rnum = i < rhs.size() ? rhs[i] - '0' : 0;
      if (lnum + rnum + carry >= 10) {
        ans++;
        carry = 1;
      } else {
        carry = 0;
      }
      result += std::to_string((lnum + rnum + adv_carry) % 10);
      adv_carry = carry;
    }
    if(adv_carry > 0){
        result += std::to_string(adv_carry);
    }
    return result;
  };
  std::string mempty("");
  std::reduce(seq.begin(), seq.end(), mempty, mappend);

  std::cout << ans << "\n";
}
