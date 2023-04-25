// 自分の得意な言語で
// Let's チャレンジ！！

// clang-format off
#include <bits/stdc++.h> 
#include <functional>
#include <queue>
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
  ll n;
  read(n);
  std::vector<ll> a(n + 1);
  std::unordered_map<ll,int> mp;
  bool no = false;
  bool exists2 = false;
  bool exists3 = false;
  bool nosolu = false;


  rep1(i, n) {
    read(a[i]);
    mp[a[i]]++;
    if(mp[a[i]] == 2) {
      exists2 = true;
      if(a[i] != n){
        nosolu = true;
      }
    }
    else if(mp[a[i]] > 2) exists3 = true;
  }
  if (n == 1) {
    std::cout << "YES\n" << a[1] << "\n" << a[1] << "\n";
    return;
  }
  if(nosolu || exists3){
    std::cout << "NO\n";
    return;
  }
  if(!exists2){
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
  using S = std::pair<ll,int>;
  std::vector<S> app1, app2;
  std::vector<ll> free;
  rep1(i, n){
    if(!mp.count(n)){
      free.push_back()
    }
  }

}
