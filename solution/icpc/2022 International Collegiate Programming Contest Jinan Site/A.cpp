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
   read(t);
  // std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
  rep1(i, t) solve(t);
  return 0;
}
// clang-format on

#define int ll
std::vector<int> seq;
std::set<int> div2;

int gain_op_times(int num, int target){
  if(num == target){
    return 0;
  }
  if(num < target){
    return target - num;
  }
  int times= 0;
  while(num / 2 >= target){
    times++;
    num/=2;
  }
  int res = (num - target) + times;
  if(num / 2 > 0){
      res = std::min(res, (target - num/2) + 1 + times) ;
  }

  return res;
}

void solve(const std::size_t testcase) {
  int n, m;
  read(n, m);
  seq.resize(n);
  div2.clear();

  rep(i, n) {
    int a;
    read(a);
    seq[i] = a;
    while(a != 0){
      div2.insert(a);
      a/=2;
    }
  }

  ll ans = std::numeric_limits<ll>::max();
  for(auto target: div2) {
    std::vector<int> diff(n);
    rep(i, n) diff[i] = gain_op_times(seq[i], target);
    std::sort(diff.begin(), diff.end());
    ll cur_ans = std::accumulate(diff.begin(), diff.end() - m, 0LL);
    ans = std::min(cur_ans, ans);
  }
  std::cout << ans << "\n";
}
