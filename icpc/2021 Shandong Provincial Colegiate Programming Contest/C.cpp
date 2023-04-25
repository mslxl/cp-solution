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

std::set<std::pair<int,int>> links;

int top = 1;
void dfs(int x, int cnt){
  if(cnt == 2) return;
  cnt--;
  if(cnt % 2 == 1 || cnt == 2){
    links.insert(std::make_pair(x, ++top));
    dfs(top, cnt);
  }else{
    links.insert(std::make_pair(x, ++top));
    links.insert(std::make_pair(x, ++top));
    dfs(top, cnt * 2);
  }
}

int k;
void solve(const std::size_t testcase) {
  std::cin >> k;

  std::cout << links.size() + 1 << "\n";
  for(auto &item: links){
    std::cout << item.first << " " << item.second << "\n";
  }
}
